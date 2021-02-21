.PHONY: clean all linuxX86 switch


export MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
export ROOTDIR := $(dir $(MAKEFILE_PATH))

export TOP_OUTDIR	:= out

all: linux switch

linux:
	@[ -d $@ ] || mkdir -p $(TOP_OUTDIR)/$@
	@$(MAKE) -C $(TOP_OUTDIR)/$@ -f $(ROOTDIR)/linux.mk

switch:
	@[ -d $@ ] || mkdir -p $(TOP_OUTDIR)/$@
	@$(MAKE) -C $(TOP_OUTDIR)/$@ -f $(ROOTDIR)/switch.mk

clean:
	@echo clean ...
	@rm -rf out *.bz2
