#include "../../../Atmosphere-libs/libstratosphere/source/dmnt/dmntcht.h"
#include <csight/Setup.hpp>
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