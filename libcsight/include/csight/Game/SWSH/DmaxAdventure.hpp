#pragma once

#include <csight/Types.hpp>
#include <memory>
#include <vector>

namespace csight::game::swsh {
  struct DmaxAdventureTemplate {
    u16 species;
    u16 altForm;
    bool isBoss;
  };

  struct DmaxAdventure {
    std::vector<DmaxAdventureTemplate> rentals;
    std::vector<DmaxAdventureTemplate> encounters;
  };

  std::shared_ptr<DmaxAdventure> generateDmaxAdventure(u64 seed, u8 npcCount);
}