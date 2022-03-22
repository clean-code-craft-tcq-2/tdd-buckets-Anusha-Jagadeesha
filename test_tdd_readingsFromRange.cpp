#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "readingsFromRange.h"
#include <map>
#include <bits/stdc++.h>

TEST_CASE("test readings from ranges")
{
    std::string* out = getReadingsFromRanges({4, 5});

    std::cout << "charging samples" << std::endl;
    for (int i = 0; i < 1; i++)
    {
        REQUIRE(out[i] == "4-5,2");
    }
}

// TEST_CASE("test readings from different range")
// {
//     std::string* testOutMap = getReadingsFromRanges({10, 11, 12, 13});

//     std::map<std::string, int>::iterator it;
//     std::cout << "charging samples from diff range" << std::endl;
//     for (it = testOutMap.begin(); it != testOutMap.end(); it++)
//     {
//         REQUIRE(it->first == "10-13");
//         REQUIRE(it->second == 4);
//     }
// }