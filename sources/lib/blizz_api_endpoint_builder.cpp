#include "blizz_api_endpoint_builder.hpp"

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
   mItemId = ItemId;
   return *this;
}