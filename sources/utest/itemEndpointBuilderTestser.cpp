#include "blizz_api_endpoint_builder.hpp"

int main()
{
    std::string t1Default = BlizzItemEndpointBuilder::GetBuilder().BuildString();
    if( t1Default != "https://eu.api.battle.net/wow/item/12345?locale=en_GB" )
    {
        return -1;
    }

    std::string t2UsDEDE72344rndVal = BlizzItemEndpointBuilder::GetBuilder()
                          .WithCommunityArea(BLIZZARD_WOW_COMM::BWC_US)
                          .WithLocale(BLIZZARD_LOCALE::BL_DE_DE)
                          .WithItemId(72344)
                          .WithJsonPString("rndVal")
                          .BuildString();
    if( t2UsDEDE72344rndVal != "https://us.api.battle.net/wow/item/72344?locale=de_DE&jsonp=rndVal" )
    {
        return -1;
    }

    return 0;
}