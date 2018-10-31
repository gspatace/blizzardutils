#pragma once

#include "blizz_api_mapper.hpp"

BlizzardTermMapper::BlizzardTermMapper()
   :mCommunityMap
      {
       { BLIZZARD_WOW_COMM::BWC_US, "US" },
       { BLIZZARD_WOW_COMM::BWC_KR, "KR" },
       { BLIZZARD_WOW_COMM::BWC_TW, "TW" },
       { BLIZZARD_WOW_COMM::BWC_EU, "EU" } 
      }
   , mLocaleMap
      {
         { BLIZZARD_LOCALE::BL_EN_GB, "en_GB"},
         { BLIZZARD_LOCALE::BL_DE_DE, "de_DE" }
      }
{

}

std::string BlizzardTermMapper::GetCommunityValue(BLIZZARD_WOW_COMM CommValue)
{
   return mCommunityMap[CommValue];
}

std::string BlizzardTermMapper::GetLocaleValue(BLIZZARD_LOCALE LocaleValue)
{
   return mLocaleMap[LocaleValue];
}