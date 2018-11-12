#pragma once

#include <string>
#include <map>

#include "blizz_api_defines.hpp"

namespace blizzard
{
class BlizzardTermMapper
{
  public:
    static BlizzardTermMapper& Instance();

    std::string GetCommunityValue(BLIZZARD_WOW_COMM CommValue);
    std::string GetLocaleValue(BLIZZARD_LOCALE LocaleValue);

  private:
    BlizzardTermMapper();
    std::map<BLIZZARD_WOW_COMM, std::string> mCommunityMap;
    std::map<BLIZZARD_LOCALE, std::string> mLocaleMap;
};

} //namespace blizzard