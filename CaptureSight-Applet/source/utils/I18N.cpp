#include <borealis.hpp>
#include <csight/core>
#include <fstream>
#include <stdio.h>
#include <string>
#include <utils/I18N.hpp>
#include <vector>

nlohmann::json g_translations;

std::string getTranslationCode() {
  auto language = getSystemLanguage();
  switch (language) {
    case Language::Spanish:
      return "es";
    case Language::German:
      return "de";
    case Language::French:
      return "fr";
    case Language::ChineseSimplified:
      return "chs";
    case Language::ChineseTraditional:
      return "cht";
    case Language::Italian:
      return "it";
    case Language::English:
    default:
      return "en";
  }
}

I18N::I18N() {
  this->loadTranslations();
}

void I18N::loadTranslations() {
  std::ifstream translations(BOREALIS_ASSET("i18n/" + getTranslationCode() + ".json"));

  if (translations.good()) {
    translations >> g_translations;
  }

  translations.close();
}

std::string I18N::translate(std::string word) {
  return g_translations["app"].value(word, word);
}

std::string I18N::translate(std::string category, std::string word) {
  return g_translations.at(category).value(word, word);
}