#pragma once

#include <csight/Enums/Ability.hpp>
#include <csight/Game/SWSH/RaidTemplateTables.hpp>
#include <csight/PKM/PKM.hpp>
#include <csight/Types.hpp>
#include <vector>

namespace csight::pkm {
  class RaidPokemon : public PKM {
   public:
    RaidPokemon(u64 seed, game::swsh::RaidEncounter spawn, u32 playerSIDTID);
    u32 getEC();
    u32 getPID();
    u32 getSIDTID();
    u16 getSpecies();
    std::vector<u8> getIVs();
    u16 getAbility();
    enums::Ability getAbilitySlot();
    u64 getRaidSeed();
    u16 getForm();
    bool getIsEgg();
    u16 getMove(u8 slot);
    u8 getNature();
    bool getIsValid();

   private:
    u64 m_seed;
    u32 m_EC;
    u32 m_PID;
    u32 m_SIDTID;
    game::swsh::RaidEncounter m_spawn;
    std::vector<u8> m_IVs;
    enums::Ability m_abilitySlot = enums::Ability::First;
  };
}
