#include <csight/Setup.hpp>

#ifdef __SWITCH__
#include "../../../Atmosphere-libs/libstratosphere/source/dmnt/dmntcht.h"
#include <switch.h>

void initializeCsightCore() {
  setInitialize();
  dmntchtInitialize();
  dmntchtForceOpenCheatProcess();
}

void cleanupCsightCore() {
  dmntchtExit();
  setExit();
}

#else

void initializeCsightCore() { }

void cleanupCsightCore() { }

#endif