#pragma once

#include "blizz_api_mapper.hpp"

BlizzardTermMapper::BlizzardTermMapper()
   :mCommunityMap
      {
       { BLIZZARD_WOW_COMM::BWC_US, "us" },
       { BLIZZARD_WOW_COMM::BWC_KR, "kr" },
       { BLIZZARD_WOW_COMM::BWC_TW, "tw" },
       { BLIZZARD_WOW_COMM::BWC_EU, "eu" } 
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