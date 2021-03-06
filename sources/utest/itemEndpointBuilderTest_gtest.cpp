#include "blizz_api_endpoint_builder.hpp"

#include <gtest/gtest.h>

using BlizzItemEndpointBuilder = blizzard::ItemEndpointBuilder;
using BlizzItemSetEndpointBuilder = blizzard::ItemSetEndpointBuilder;
using WOW_COMM = blizzard::BLIZZARD_WOW_COMM;
using WOW_LOCALE = blizzard::BLIZZARD_LOCALE;
namespace testing
{

TEST(ItemEndpointBuilderTest, DefaultParamsTest)
{
    std::string actual = BlizzItemEndpointBuilder::GetBuilder().BuildString();
    std::string expected =
        "https://eu.api.blizzard.com/wow/item/12345?locale=en_GB&access_token=abcdefghijklmnopqrstuvwxyz";
    EXPECT_EQ(expected, actual);
}

TEST(ItemEndpointBuilderTest, UsCommDeLocaleRndVal)
{
    std::string actual = BlizzItemEndpointBuilder::GetBuilder()
                             .WithCommunityArea(WOW_COMM::BWC_US)
                             .WithLocale(WOW_LOCALE::BL_DE_DE)
                             .WithItemId(72344)
                             .WithJsonPString("rndVal")
                             .BuildString();

    std::string expected =
        "https://us.api.blizzard.com/wow/item/72344?locale=de_DE&jsonp=rndVal&access_token=abcdefghijklmnopqrstuvwxyz";
    EXPECT_EQ(expected, actual);
}

TEST(ItemEndpointBuilderTest, DefaultWithApiKey)
{
    std::string actual = BlizzItemEndpointBuilder::GetBuilder()
                             .WithItemId(14423)
                             .WithAccessToken("SomeApiKeyHere")
                             .BuildString();

    std::string expected = "https://eu.api.blizzard.com/wow/item/14423?locale=en_GB&access_token=SomeApiKeyHere";
    EXPECT_EQ(expected, actual);
}

TEST(ItemSetEndpointBuilderTest, DefaultParamsTest)
{
    std::string actual = BlizzItemSetEndpointBuilder::GetBuilder().BuildString();
    std::string expected = "https://eu.api.blizzard.com/wow/item/set/1060?locale=en_GB&access_token=abcdefghijklmnopqrstuvwxyz";
    EXPECT_EQ(expected, actual);
}

TEST(ItemSetEndpointBuilderTest, EuCommItemSet)
{
    std::string actual = BlizzItemSetEndpointBuilder::GetBuilder()
                             .WithItemSetId(1061)
                             .WithLocale(WOW_LOCALE::BL_FR_FR)
                             .BuildString();

    std::string expected = "https://eu.api.blizzard.com/wow/item/set/1061?locale=fr_FR&access_token=abcdefghijklmnopqrstuvwxyz";
    EXPECT_EQ(expected, actual);
}
} // namespace testing