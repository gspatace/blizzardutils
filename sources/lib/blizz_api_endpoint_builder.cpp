#include <sstream>

#include "blizz_api_endpoint_builder.hpp"
#include "blizz_api_mapper.hpp"

BlizzItemEndpointBuilder::BlizzItemEndpointBuilder()
   : mItemId(1311)
   , mCommunityArea(BLIZZARD_WOW_COMM::BWC_EU)
   , mLocale(BLIZZARD_LOCALE::BL_EN_GB)
{}

BlizzItemEndpointBuilder& BlizzItemEndpointBuilder::WithCommunityArea(BLIZZARD_WOW_COMM CommunityArea)
{
   mCommunityArea = CommunityArea;
   return *this;
}

BlizzItemEndpointBuilder& BlizzItemEndpointBuilder::WithLocale(BLIZZARD_LOCALE Locale)
{
   mLocale = Locale;
   return *this;
}

BlizzItemEndpointBuilder& BlizzItemEndpointBuilder::WithItemId(int ItemId)
{
   if (ItemId < 0)
      throw std::invalid_argument("Item id must be greater than 0");

   mItemId = ItemId;
   return *this;
}

std::string BlizzItemEndpointBuilder::Build()
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

bool BlizzItemEndpointBuilder::IsValid()
{
   return mItemId >= 0 ? true : false;
}