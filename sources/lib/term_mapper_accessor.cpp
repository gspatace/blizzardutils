#include "term_mapper_accessor.hpp"

using namespace blizzard;

std::string TermMapperAccessor::GetCommunityValue(BLIZZARD_WOW_COMM CommValue)
{
    return BlizzardTermMapper::Instance().GetCommunityValue(CommValue);
}

std::string TermMapperAccessor::GetLocaleValue(BLIZZARD_LOCALE LocaleValue)
{
    return BlizzardTermMapper::Instance().GetLocaleValue(LocaleValue);
}