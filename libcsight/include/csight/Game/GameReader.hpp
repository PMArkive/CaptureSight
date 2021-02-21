#pragma once

#include <csight/PKM/PKM.hpp>
#include <csight/TitleIds.hpp>
#include <csight/Types.hpp>
#include <csight/Utils.hpp>
#include <vector>

#ifdef __SWITCH__
#include "../../../../Atmosphere-libs/libstratosphere/source/dmnt/dmntcht.h"
#endif

namespace csight::game {
  template <class PKMType>
  class GameReader {
   public:
    GameReader() { m_isDebugServiceRunning = utils::checkIfServiceIsRunning("dmnt:cht"); }

    Result attach() {
#ifdef __SWITCH__
      DmntCheatProcessMetadata metadata;
      Result result = dmntchtGetCheatProcessMetadata(&metadata);

      if (R_SUCCEEDED(result)) {
        m_heapBase = metadata.heap_extents.base;
        m_titleId = metadata.title_id;
      }

      return result;
#else
      m_titleId = SWORD_TITLE_ID;
      return 0;
#endif
    }

    bool getIsPokemonRunning() { return (m_titleId == SWORD_TITLE_ID) || (m_titleId == SHIELD_TITLE_ID); }

    bool getIsServiceRunning() { return m_isDebugServiceRunning; }

    u64 getTitleId() { return m_titleId; }

    virtual std::vector<std::shared_ptr<PKMType>> readBoxes(u16 box) = 0;
    virtual std::vector<std::shared_ptr<PKMType>> readParty() = 0;
    virtual std::shared_ptr<PKMType> readWild() = 0;
    virtual u32 getTrainerSIDTID() = 0;

   protected:
    Result readHeap(u64 offset, void *buffer, size_t size) {
#ifdef __SWITCH__
      return dmntchtReadCheatProcessMemory(m_heapBase + offset, buffer, size);
#else
      // A non-zero code is a fail code
      return 1;
#endif
    }

    std::shared_ptr<PKMType> readPKM(u64 offset, u32 pkmSize) {
      u8 *pkmBytes = new u8[pkmSize];

      this->readHeap(offset, pkmBytes, pkmSize);
      auto pkm = std::make_shared<PKMType>(pkmBytes);

      delete[] pkmBytes;

      return pkm->getIsValid() ? pkm : std::make_shared<PKMType>();
    }

    std::vector<std::shared_ptr<PKMType>> readPKMs(u64 offset, u32 amount, u32 pkmSize) {
      std::vector<std::shared_ptr<PKMType>> pk8s;
      u32 size = pkmSize * amount;
      u8 *pkmBytes = new u8[size];

      this->readHeap(offset, pkmBytes, size);

      for (u32 i = 0; i < amount; i++) {
        pk8s.push_back(std::make_shared<PKMType>(pkmBytes + (i * pkmSize)));
      }

      delete[] pkmBytes;

      return pk8s;
    }

   private:
    bool m_isDebugServiceRunning = false;
    u64 m_heapBase = 0;
    u64 m_titleId = 0;
  };
}
