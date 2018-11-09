#pragma once

#include <map>
#include <string>

#include "blizz_api_mapper.hpp"

#ifdef WIN32
#ifdef BLIZZ_API_EXPORTS
#define mDLLIMPORTEXPORT __declspec(dllexport)
#else
#define mDLLIMPORTEXPORT __declspec(dllimport)
#endif // BLIZZ_API_EXPORTS
#else  // WIN32
#define mDLLIMPORTEXPORT
#endif

class mDLLIMPORTEXPORT TermMapperAccessor
{
  public:
    static std::string GetCommunityValue(BLIZZARD_WOW_COMM CommValue);
    static std::string GetLocaleValue(BLIZZARD_LOCALE LocaleValue);
};
