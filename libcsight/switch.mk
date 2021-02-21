#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

include $(DEVKITPRO)/libnx/switch_rules

#---------------------------------------------------------------------------------
# SOURCES is a list of directories containing source code
# INCLUDES is a list of directories containing header files
# BUILD_RULES is the name of this file
#---------------------------------------------------------------------------------
SOURCES		:=	../Atmosphere-libs/libstratosphere/source/dmnt
INCLUDES	:=	../Atmosphere-libs/libstratosphere/source/dmnt
BUILD_RULES	:=	$(ROOTDIR)/switch.mk

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
ARCH	:=	-march=armv8-a+crc+crypto -mtune=cortex-a57 -mtp=soft -fPIE
ASFLAGS	:=	-g $(ARCH)
EXTRA_CFLAGS	:=	-D__SWITCH__
EXTRA_CXXFLAGS	:=	-std=gnu++20

#---------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level containing
# include and lib
#---------------------------------------------------------------------------------
LIBDIRS := $(PORTLIBS)

include $(ROOTDIR)/common.mk
