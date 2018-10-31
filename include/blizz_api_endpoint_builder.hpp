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

class mDLLIMPORTEXPORT BlizzEndpointBuilder
{
public:
   BlizzEndpointBuilder();
   //BlizzEndpointBuilder(const BlizzEndpointBuilder&) = delete;
   //BlizzEndpointBuilder& operator=(const BlizzEndpointBuilder&) = delete;
   //BlizzEndpointBuilder(BlizzEndpointBuilder&&) = delete;
   //BlizzEndpointBuilder& operator=( BlizzEndpointBuilder&&) = delete;

   BlizzEndpointBuilder* WithCommunityArea(BLIZZARD_WOW_COMM CommunityArea);
   BlizzEndpointBuilder* WithLocale(BLIZZARD_LOCALE Locale);

   virtual std::string Build() = 0;
   protected:
   virtual bool IsValid() = 0;
   BLIZZARD_WOW_COMM mCommunityArea;
   BLIZZARD_LOCALE mLocale;
};

class mDLLIMPORTEXPORT BlizzItemEndpointBuilder: public BlizzEndpointBuilder
{
public:
   BlizzItemEndpointBuilder();
   //BlizzItemEndpointBuilder(const BlizzItemEndpointBuilder&) = delete;
   //BlizzItemEndpointBuilder& operator=(const BlizzItemEndpointBuilder&) = delete;
   //BlizzItemEndpointBuilder(BlizzItemEndpointBuilder&&) = delete;
   //BlizzItemEndpointBuilder& operator=(BlizzItemEndpointBuilder&&) = delete;

   BlizzItemEndpointBuilder* WithItemId(int ItemId);

   virtual std::string Build() override;
   virtual bool IsValid() override;
private:
   int mItemId;
};

