#pragma once

#include <string>
#include <sstream>

#include "blizz_api_defines.hpp"
#include "blizz_api_mapper.hpp"

#ifdef WIN32
#ifdef BLIZZ_API_EXPORTS
#define mDLLIMPORTEXPORT __declspec(dllexport)
#else
#define mDLLIMPORTEXPORT __declspec(dllimport)
#endif //BLIZZ_API_EXPORTS
#else //WIN32
#define mDLLIMPORTEXPORT 
#endif

template<typename T>
class  Builder
{
public:
   static T GetBuilder() {
      return{};
   }

   T& build() {
      return static_cast<T&>(*this);
   }
};

template<typename T>
class  BlizzEndpointBuilder : public Builder<T>
{
public:
   BlizzEndpointBuilder()
      : mCommunityArea(BLIZZARD_WOW_COMM::BWC_EU)
      , mLocale(BLIZZARD_LOCALE::BL_EN_GB)
   {}
   
   T& WithCommunityArea(BLIZZARD_WOW_COMM CommunityArea)
   {
      mCommunityArea = CommunityArea;
      return static_cast<T&>(*this);
   }

   T& WithLocale(BLIZZARD_LOCALE Locale)
   {
      mLocale = Locale;
      return static_cast<T&>(*this);
   }

   virtual std::string Build() = 0;
   protected:
   virtual bool IsValid() = 0;
   BLIZZARD_WOW_COMM mCommunityArea;
   BLIZZARD_LOCALE mLocale;
};

class  BlizzItemEndpointBuilder: public BlizzEndpointBuilder<BlizzItemEndpointBuilder>
{
public:
   BlizzItemEndpointBuilder()
      : BlizzEndpointBuilder()
      , mItemId(12345)
   {}

   BlizzItemEndpointBuilder& WithItemId(int ItemId)
   {
      if (ItemId < 0)
         throw std::invalid_argument("Item id must be greater than 0");

      mItemId = ItemId;
      return *this;
   }

   virtual std::string Build()
   {
      std::ostringstream endpointOss;
      endpointOss << "https://";
      endpointOss << BlizzardTermMapper::Instance().GetCommunityValue(mCommunityArea);
      endpointOss << ".api.battle.net/wow/";
      endpointOss << "item/";
      endpointOss << mItemId;
      endpointOss << "?locale=";
      endpointOss << BlizzardTermMapper::Instance().GetLocaleValue(mLocale);

      return endpointOss.str();
   }

   virtual bool IsValid() 
   {
      return mItemId >= 0 ? true : false;
   }
private:
   int mItemId;
};

