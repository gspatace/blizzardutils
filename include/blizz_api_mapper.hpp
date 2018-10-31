#pragma once

#include <string>
#include <map>

#include "blizz_api_defines.hpp"

#ifdef WIN32
#ifdef BLIZZ_API_EXPORTS
#define mDLLIMPORTEXPORT __declspec(dllexport)
#else
#define mDLLIMPORTEXPORT __declspec(dllimport)
#endif //BLIZZ_API_EXPORTS
#else //WIN32
#define mDLLIMPORTEXPORT 
#endif

class mDLLIMPORTEXPORT BlizzardTermMapper
{
public:
   static BlizzardTermMapper& Instance()
   {
      static BlizzardTermMapper mTheInstance;
      return mTheInstance;
   }

   std::string GetCommunityValue(BLIZZARD_WOW_COMM CommValue);
   std::string GetLocaleValue(BLIZZARD_LOCALE LocaleValue);
private:
   BlizzardTermMapper();
   std::map<BLIZZARD_WOW_COMM, std::string> mCommunityMap;
   std::map<BLIZZARD_LOCALE, std::string> mLocaleMap;
};