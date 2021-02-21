#include <csight/Language.hpp>

#ifdef __SWITCH__
#include <switch.h>

Language getSystemLanguage() {
  u64 languageCode = 0;
  SetLanguage language = SetLanguage_ENUS;
  setGetSystemLanguage(&languageCode);
  setMakeLanguage(languageCode, &language);
  switch (language) {
    case SetLanguage_ZHCN:
    case SetLanguage_ZHHANS:
      return Language::ChineseSimplified;
    case SetLanguage_ZHTW:
    case SetLanguage_ZHHANT:
      return Language::ChineseTraditional;
    case SetLanguage_KO:
      return Language::Korean;
    case SetLanguage_IT:
      return Language::Italian;
    case SetLanguage_JA:
      return Language::Japanese;
    case SetLanguage_FR:
    case SetLanguage_FRCA:
      return Language::French;
    case SetLanguage_ES:
    case SetLanguage_ES419:
      return Language::Spanish;
    case SetLanguage_DE:
      return Language::German;
    case SetLanguage_NL:
      return Language::Dutch;
    case SetLanguage_PT:
      return Language::Portuguese;
    case SetLanguage_RU:
      return Language::Russian;
    case SetLanguage_ENUS:
    case SetLanguage_ENGB:
    default:
      return Language::English;
  }
}

#else
Language getSystemLanguage() {
  // Real language detection should be added later
  // probably using a user config
  return Language::English;
}
#endif