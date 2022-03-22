#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "readingsFromRange.h"
#include <map>
#include <bits/stdc++.h>

FindRangeReadings m_cacheRangeReadings;

TEST_CASE("test readings from ranges")
{
    m_cacheRangeReadings.cacheReadingsFromRanges({4, 5});
    m_cacheRangeReadings.printRangeandReadings();
    REQUIRE(m_cacheRangeReadings.m_cacheRange[0] == "4-5,2");
}

TEST_CASE("test readings from continuous range")
{
    m_cacheRangeReadings.cacheReadingsFromRanges({10, 11, 12, 13});
    m_cacheRangeReadings.printRangeandReadings();
    REQUIRE(m_cacheRangeReadings.m_cacheRange[1] == "10-13,4");
}

TEST_CASE("test readings from different range")
{
    m_cacheRangeReadings.cacheReadingsFromRanges({3,3,4,5,10,11,12});
    m_cacheRangeReadings.printRangeandReadings();
    REQUIRE(m_cacheRangeReadings.m_cacheRange[2] == "3-5,4");
    REQUIRE(m_cacheRangeReadings.m_cacheRange[3] == "10-12,3");
}

TEST_CASE("test readings for multiple same readings")
{
    m_cacheRangeReadings.cacheReadingsFromRanges({1,2,2});
    m_cacheRangeReadings.printRangeandReadings();
    REQUIRE(m_cacheRangeReadings.m_cacheRange[4] == "1-2,3");
}