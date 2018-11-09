#include "blizz_api_mapper.hpp"

BlizzardTermMapper& BlizzardTermMapper::Instance()
{
    static BlizzardTermMapper mTheInstance;
    return mTheInstance;
}

BlizzardTermMapper::BlizzardTermMapper()
    : mCommunityMap{{BLIZZARD_WOW_COMM::BWC_US, "us"},
                    {BLIZZARD_WOW_COMM::BWC_KR, "kr"},
                    {BLIZZARD_WOW_COMM::BWC_TW, "tw"},
                    {BLIZZARD_WOW_COMM::BWC_EU, "eu"}}
    , mLocaleMap{{BLIZZARD_LOCALE::BL_EN_GB, "en_GB"},
                 {BLIZZARD_LOCALE::BL_DE_DE, "de_DE"},
                 {BLIZZARD_LOCALE::BL_ES_ES, "es_ES"},
                 {BLIZZARD_LOCALE::BL_FR_FR, "fr_FR"},
                 {BLIZZARD_LOCALE::BL_IT_IT, "it_IT"},
                 {BLIZZARD_LOCALE::BL_PL_PL, "pl_PL"},
                 {BLIZZARD_LOCALE::BL_PT_PT, "pt_PT"},
                 {BLIZZARD_LOCALE::BL_RU_RU, "ru_RU"},
                 {BLIZZARD_LOCALE::BL_ZH_TW, "zh_TW"},
                 {BLIZZARD_LOCALE::BL_KO_KR, "ko_KR"}}
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