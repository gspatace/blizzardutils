#pragma once

#include <string>
#include <sstream>

#include "blizz_api_defines.hpp"
#include "blizz_api_mapper.hpp"
#include "term_mapper_accessor.hpp"

template<typename T>
class Builder
{
  public:
    static T GetBuilder()
    {
        return {};
    }
};

template<typename T>
class BlizzEndpointBuilder : public Builder<T>
{
  public:
    BlizzEndpointBuilder()
        : mCommunityArea(BLIZZARD_WOW_COMM::BWC_EU)
        , mLocale(BLIZZARD_LOCALE::BL_EN_GB)
        , mJsonp("")
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
};

class BlizzItemEndpointBuilder
    : public BlizzEndpointBuilder<BlizzItemEndpointBuilder>
{
  public:
    BlizzItemEndpointBuilder()
        : BlizzEndpointBuilder()
        , mItemId(12345)
        , mEndpointSpecificUri("item/")
    {
    }

    BlizzItemEndpointBuilder& WithItemId(int ItemId)
    {
        if (ItemId < 0)
            throw std::invalid_argument("Item id must be greater than 0");

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
    int mItemId;
    std::string mEndpointSpecificUri;
};

class BlizzItemSetEndpointBuilder
    : public BlizzEndpointBuilder<BlizzItemSetEndpointBuilder>
{
  public:
    BlizzItemSetEndpointBuilder()
        : BlizzEndpointBuilder()
        , mItemSetId(1060)
        , mEndpointSpecificUri("item/set/")
    {
    }

    BlizzItemSetEndpointBuilder& WithItemSetId(int ItemSetId)
    {
        if (ItemSetId < 0)
            throw std::invalid_argument("Item id must be greater than 0");

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
    int mItemSetId;
    std::string mEndpointSpecificUri;
};