#include <iostream>

#include "blizz_api_endpoint_builder.hpp"

int main(int argc, char* argv[])
{
   BlizzItemEndpointBuilder endpointBuilder;
   endpointBuilder
      .WithCommunityArea(BLIZZARD_WOW_COMM::BWC_US)
      .WithLocale(BLIZZARD_LOCALE::BL_DE_DE)
      .WithItemId(72344);
   std::cout << endpointBuilder.Build();


   std::cout << std::endl<<"final";
   return 0;
}