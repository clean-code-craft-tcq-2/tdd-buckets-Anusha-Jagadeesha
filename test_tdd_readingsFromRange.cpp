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
    REQUIRE(m_cacheRangeReadings.m_storeRange[0] == "4-5,2");
}

TEST_CASE("test readings from continuous range")
{
    m_cacheRangeReadings.cacheReadingsFromRanges({10, 11, 12, 13});
    m_cacheRangeReadings.printRangeandReadings();
    REQUIRE(m_cacheRangeReadings.m_storeRange[1] == "10-13,4");
}

TEST_CASE("test readings from different range")
{
    m_cacheRangeReadings.cacheReadingsFromRanges({3,3,4,5,10,11,12});
    m_cacheRangeReadings.printRangeandReadings();
    REQUIRE(m_cacheRangeReadings.m_storeRange[2] == "3-5,4");
    REQUIRE(m_cacheRangeReadings.m_storeRange[3] == "10-12,3");
}

TEST_CASE("test readings for multiple same readings")
{
    m_cacheRangeReadings.cacheReadingsFromRanges({1,2,2});
    m_cacheRangeReadings.printRangeandReadings();
    REQUIRE(m_cacheRangeReadings.m_storeRange[4] == "1-2,3");
}

TEST_CASE("test readings A2D")
{
    m_cacheRangeReadings.cacheReadingsFromRanges({0,1250,2456,3588});
    m_cacheRangeReadings.printRangeandReadings();
    REQUIRE(m_cacheRangeReadings.m_storeRange[5] == "0-0,1");
    REQUIRE(m_cacheRangeReadings.m_storeRange[6] == "1250-1250,1");
    REQUIRE(m_cacheRangeReadings.m_storeRange[7] == "2456-2456,1");
    REQUIRE(m_cacheRangeReadings.m_storeRange[8] == "3588-3588,1");

    REQUIRE(m_cacheRangeReadings.m_currentSamplesAfterA2D[14] == 0);
    REQUIRE(m_cacheRangeReadings.m_currentSamplesAfterA2D[15] == 3);
    REQUIRE(m_cacheRangeReadings.m_currentSamplesAfterA2D[16] == 6);
    REQUIRE(m_cacheRangeReadings.m_currentSamplesAfterA2D[17] == 9);
}

TEST_CASE("test for invalid range")
{
    REQUIRE(m_cacheRangeReadings.sortInputRange({4095,4096}) == false);
}

TEST_CASE("test convertToAmps")
{
    REQUIRE(m_cacheRangeReadings.convertToAmps(100) == 0);
    REQUIRE(m_cacheRangeReadings.convertToAmps(500) == 1);
    REQUIRE(m_cacheRangeReadings.convertToAmps(1000) == 2);
    REQUIRE(m_cacheRangeReadings.convertToAmps(1400) == 3);
    REQUIRE(m_cacheRangeReadings.convertToAmps(1800) == 4);
    REQUIRE(m_cacheRangeReadings.convertToAmps(2100) == 5);
    REQUIRE(m_cacheRangeReadings.convertToAmps(2600) == 6);
    REQUIRE(m_cacheRangeReadings.convertToAmps(3000) == 7);
    REQUIRE(m_cacheRangeReadings.convertToAmps(3400) == 8);
    REQUIRE(m_cacheRangeReadings.convertToAmps(3800) == 9);
    REQUIRE(m_cacheRangeReadings.convertToAmps(4094) == 10);
}