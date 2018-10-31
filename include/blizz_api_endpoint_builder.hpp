#pragma once

#include <string>

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

class mDLLIMPORTEXPORT BlizzItemEndpointBuilder
{
public:
   BlizzItemEndpointBuilder();
   BlizzItemEndpointBuilder& WithCommunityArea(BLIZZARD_WOW_COMM CommunityArea);
   BlizzItemEndpointBuilder& WithLocale(BLIZZARD_LOCALE Locale);
   BlizzItemEndpointBuilder& WithItemId(int ItemId);

   std::string Build();
private:
   bool IsValid();
   int mItemId;
   BLIZZARD_WOW_COMM mCommunityArea;
   BLIZZARD_LOCALE mLocale;
};