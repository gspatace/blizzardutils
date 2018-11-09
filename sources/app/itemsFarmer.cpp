#include <iostream>

#include "blizz_api_endpoint_builder.hpp"

int main()
{
    std::string str = BlizzItemEndpointBuilder::GetBuilder()
                          .WithCommunityArea(BLIZZARD_WOW_COMM::BWC_US)
                          .WithLocale(BLIZZARD_LOCALE::BL_DE_DE)
                          .WithItemId(72344)
                          .WithJsonPString("rndVal")
                          .BuildString();
    std::cout << str << std::endl;

    std::string str2 = BlizzItemEndpointBuilder::GetBuilder().BuildString();
    std::cout << str2 << std::endl;

    std::cout << std::endl
              << "Successfull" << std::endl;
    return 0;
}
