ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>/devkitpro")
endif

# Currently shared for the generic typedefs
LIBNX	?=	$(DEVKITPRO)/libnx

#---------------------------------------------------------------------------------
# TARGET is the name of the output
# SOURCES is a list of directories containing source code
# INCLUDES is a list of directories containing header files
# DATA is a list of directories containing data files
#---------------------------------------------------------------------------------
TARGET		:=	csight
SOURCES		+=	source source/csight source/csight/Game source/csight/Game/SWSH source/csight/PKM source/csight/Resources
INCLUDES	+= include include/csight include/csight/Game include/csight/Game/SWSH include/csight/PKM include/csight/Resources include/csight/RNG include/csight/Enums ../flatbuffers/include
DATA		:=	$(ROOTDIR)/data

SOURCES	:= $(foreach dir,$(SOURCES), $(ROOTDIR)/$(dir))
INCLUDES	:= $(foreach dir,$(INCLUDES), $(ROOTDIR)/$(dir))

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
CFLAGS	:=	-g -Wall -Wno-error \
			-ffunction-sections \
			-fdata-sections \
			$(ARCH) \
			$(BUILD_CFLAGS) \
			$(INCLUDE) \
			$(EXTRA_CFLAGS)

CXXFLAGS	:= $(CFLAGS) -fno-rtti -fno-exceptions $(EXTRA_CXXFLAGS)

#---------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level containing
# include and lib
#---------------------------------------------------------------------------------
LIBDIRS += $(LIBNX)

#---------------------------------------------------------------------------------
# no real need to edit anything past this point unless you need to add additional
# rules for different file extensions
#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))
#---------------------------------------------------------------------------------

export VPATH	:=	$(SOURCES) $(DATA)

CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
BINFILES	:=	$(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))

#---------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
#---------------------------------------------------------------------------------
	export LD	:=	$(CC)
#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
	export LD	:=	$(CXX)
#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

export OFILES_BIN	:=	$(addsuffix .o,$(BINFILES))
export OFILES_SRC	:=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
export OFILES 	:=	$(OFILES_BIN) $(OFILES_SRC)
export HFILES	:=	$(addsuffix .h,$(subst .,_,$(BINFILES)))

export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I$(dir)) \
			$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
			-I$(BUILD)

.PHONY: clean all

#---------------------------------------------------------------------------------
all: lib/lib$(TARGET).a lib/lib$(TARGET)d.a

lib:
	@[ -d $@ ] || mkdir -p $@

release:
	@[ -d $@ ] || mkdir -p $@

debug:
	@[ -d $@ ] || mkdir -p $@

lib/lib$(TARGET).a : lib release $(SOURCES) $(INCLUDES)
	@$(MAKE) BUILD=release OUTPUT=$(CURDIR)/$@ \
	BUILD_CFLAGS="-DNDEBUG=1 -O2" \
	DEPSDIR=$(CURDIR)/release \
	--no-print-directory -C release \
	-f $(BUILD_RULES)

lib/lib$(TARGET)d.a : lib debug $(SOURCES) $(INCLUDES)
	@$(MAKE) BUILD=debug OUTPUT=$(CURDIR)/$@ \
	BUILD_CFLAGS="-DDEBUG=1 -Og" \
	DEPSDIR=$(CURDIR)/debug \
	--no-print-directory -C debug \
	-f $(BUILD_RULES)

dist-bin: all
	@tar --exclude=*~ -cjf lib$(TARGET).tar.bz2 include lib

dist-src:
	@tar --exclude=*~ -cjf lib$(TARGET)-src.tar.bz2 include source $(BUILD_RULES)

dist: dist-src dist-bin

#---------------------------------------------------------------------------------
else

DEPENDS	:=	$(OFILES:.o=.d)

#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------
$(OUTPUT)	:	$(OFILES)

$(OFILES_SRC)	: $(HFILES)

#---------------------------------------------------------------------------------
%_bin.h %.bin.o	:	%.bin
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)


-include $(DEPENDS)

#---------------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------------

