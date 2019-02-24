#pragma once

#include <string>
#include <sstream>

#include "blizz_api_defines.hpp"
#include "blizz_api_mapper.hpp"
#include "term_mapper_accessor.hpp"

namespace blizzard
{

template<typename T>
class BaseBuilder
{
  public:
    static T GetBuilder()
    {
        return {};
    }
};

template<typename T>
class BaseEndpointBuilder : public BaseBuilder<T>
{
  public:
    BaseEndpointBuilder()
        : mCommunityArea(BLIZZARD_WOW_COMM::BWC_EU)
        , mLocale(BLIZZARD_LOCALE::BL_EN_GB)
        , mJsonp("")
        , mAccessToken("abcdefghijklmnopqrstuvwxyz")
    {
    }

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

    T& WithJsonPString(const std::string& JsonP)
    {
        mJsonp = JsonP;
        return static_cast<T&>(*this);
    }

    T& WithAccessToken(const std::string& AccessToken)
    {
        mAccessToken = AccessToken;
        return static_cast<T&>(*this);
    }

    std::string BuildString()
    {
        if (!IsValid())
            throw std::domain_error("Data needed for building endpoint is invalid");

        std::ostringstream endpointOss;
        endpointOss << "https://";
        endpointOss << TermMapperAccessor::GetCommunityValue(mCommunityArea);
        endpointOss << ".api.battle.net/wow/";
        endpointOss << BuildEndpointSpecificURI();
        endpointOss << "?locale=";
        endpointOss << TermMapperAccessor::GetLocaleValue(mLocale);

        if (mJsonp != "")
        {
            endpointOss << "&jsonp=";
            endpointOss << mJsonp;
        }

        endpointOss << "&access_token=";
        endpointOss << mAccessToken;

        return endpointOss.str();
    }

  protected:
    virtual std::string BuildEndpointSpecificURI() = 0;
    virtual bool IsValid()
    {
        return true;
    };

    BLIZZARD_WOW_COMM mCommunityArea;
    BLIZZARD_LOCALE mLocale;
    std::string mJsonp;
    std::string mAccessToken;
};

class ItemEndpointBuilder
    : public BaseEndpointBuilder<ItemEndpointBuilder>
{
  public:
    ItemEndpointBuilder()
        : BaseEndpointBuilder()
        , mItemId(12345)
        , mEndpointSpecificUri("item/")
    {
    }

    ItemEndpointBuilder& WithItemId(unsigned int ItemId)
    {
        mItemId = ItemId;
        return *this;
    }

    virtual std::string BuildEndpointSpecificURI() override
    {
        std::ostringstream oss;
        oss << mEndpointSpecificUri;
        oss << mItemId;
        return oss.str();
    }

  private:
    unsigned int mItemId;
    std::string mEndpointSpecificUri;
};

class ItemSetEndpointBuilder
    : public BaseEndpointBuilder<ItemSetEndpointBuilder>
{
  public:
    ItemSetEndpointBuilder()
        : BaseEndpointBuilder()
        , mItemSetId(1060)
        , mEndpointSpecificUri("item/set/")
    {
    }

    ItemSetEndpointBuilder& WithItemSetId(unsigned int ItemSetId)
    {
        mItemSetId = ItemSetId;
        return *this;
    }

    virtual std::string BuildEndpointSpecificURI() override
    {
        std::ostringstream oss;
        oss << mEndpointSpecificUri;
        oss << mItemSetId;
        return oss.str();
    }

  private:
    unsigned int mItemSetId;
    std::string mEndpointSpecificUri;
};

} //namespace blizzard