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
    virtual bool IsValid() = 0;
    BLIZZARD_WOW_COMM mCommunityArea;
    BLIZZARD_LOCALE mLocale;
    std::string mJsonp = "";
};

class BlizzItemEndpointBuilder
    : public BlizzEndpointBuilder<BlizzItemEndpointBuilder>
{
  public:
    BlizzItemEndpointBuilder()
        : BlizzEndpointBuilder()
        , mItemId(12345)
    {
    }

    BlizzItemEndpointBuilder& WithItemId(int ItemId)
    {
        if (ItemId < 0)
            throw std::invalid_argument("Item id must be greater than 0");

        mItemId = ItemId;
        return *this;
    }

    virtual std::string BuildEndpointSpecificURI()
    {
        std::ostringstream oss;
        oss << mEndpointSpecificUri;
        oss << mItemId;
        return oss.str();
    }

    virtual bool IsValid()
    {
        return mItemId >= 0 ? true : false;
    }

  private:
    int mItemId;
    std::string mEndpointSpecificUri = "item/";
};
