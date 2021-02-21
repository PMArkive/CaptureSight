#pragma once

#include <csight/Types.hpp>
#include <future>
#include <vector>

namespace csight::game::swsh {
  std::future<ulong> calculateRaidSeedAsync(uint ec, uint pid, std::vector<u8> ivs);
  ulong calculateRaidSeed(uint ec, uint pid, std::vector<u8> ivs);
}
