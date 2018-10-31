#pragma once

#include <string>

#include "blizz_api_defines.hpp"

class BlizzItemEndpointBuilder
{
public:
   BlizzItemEndpointBuilder();
   BlizzItemEndpointBuilder& WithCommunityArea(BLIZZARD_WOW_COMM CommunityArea);
   BlizzItemEndpointBuilder& WithLocale(BLIZZARD_LOCALE Locale);
   BlizzItemEndpointBuilder& WithItemId(int ItemId);

   std::string BuildEndpoint();
private:
   int mItemId;
   BLIZZARD_WOW_COMM mCommunityArea;
   BLIZZARD_LOCALE mLocale;
};