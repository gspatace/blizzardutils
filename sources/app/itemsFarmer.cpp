#include <iostream>

#include "blizz_api_endpoint_builder.hpp"

int main(int argc, char* argv[])
{
   //BlizzItemEndpointBuilder * endpointBuilder = new BlizzItemEndpointBuilder();
   //endpointBuilder
   //   ->WithCommunityArea(BLIZZARD_WOW_COMM::BWC_US)
   //   ->WithLocale(BLIZZARD_LOCALE::BL_DE_DE);
   //   //->WithItemId(72344);

   //endpointBuilder->WithItemId(72344);

   std::string str = BlizzItemEndpointBuilder::GetBuilder()
      .WithCommunityArea(BLIZZARD_WOW_COMM::BWC_US)
      .WithLocale(BLIZZARD_LOCALE::BL_DE_DE)
      .WithItemId(72344)
      .Build();
   std::cout << str << std::endl;

   std::string str2 = BlizzItemEndpointBuilder::GetBuilder().Build();

   std::cout << str2 << std::endl;

   std::cout << std::endl<<"final";
   return 0;
}
