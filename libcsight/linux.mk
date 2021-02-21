#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

# Contains rules for object and lib files, and does not appear to be devkitA64 specific
# This should probably be pulled out in the future
include $(DEVKITPRO)/devkitA64/base_rules

CC	:=	gcc
CXX	:=	g++
AS	:=	as
AR	:=	gcc-ar
OBJCOPY	:=	objcopy
STRIP	:=	strip
NM	:=	gcc-nm
RANLIB	:=	gcc-ranlib

#---------------------------------------------------------------------------------
# BUILD_RULES is this file
#---------------------------------------------------------------------------------
BUILD_RULES	:=	$(ROOTDIR)/linux.mk

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
EXTRA_CFLAGS	:=	-D__LINUX_X86__
EXTRA_CXXFLAGS	:=	-std=gnu++2a

include $(ROOTDIR)/common.mk
