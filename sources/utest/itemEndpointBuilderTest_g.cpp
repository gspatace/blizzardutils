#include "blizz_api_endpoint_builder.hpp"

#include <gtest/gtest.h>

namespace testing
{
class ItemEndpointBuilderTester : public Test
{
  protected:
    ItemEndpointBuilderTester(){};
    ~ItemEndpointBuilderTester(){};
};

TEST(BuilderTest, DefaultParamsTest)
{
    std::string actual = BlizzItemEndpointBuilder::GetBuilder().BuildString();
    std::string expected =
        "https://eu.api.battle.net/wow/item/12345?locale=en_GB";
    EXPECT_EQ(expected, actual);
}

TEST(BuilderTest, UsCommDeLocaleRndVal)
{
    std::string actual = BlizzItemEndpointBuilder::GetBuilder()
                             .WithCommunityArea(BLIZZARD_WOW_COMM::BWC_US)
                             .WithLocale(BLIZZARD_LOCALE::BL_DE_DE)
                             .WithItemId(72344)
                             .WithJsonPString("rndVal")
                             .BuildString();

    std::string expected =
        "https://us.api.battle.net/wow/item/72344?locale=de_DE&jsonp=rndVal";
    EXPECT_EQ(expected, actual);
}
} // namespace testing