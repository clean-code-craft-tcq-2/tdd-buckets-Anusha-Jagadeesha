#include "readingsFromRange.h"
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

void FindRangeReadings::cacheReadingsFromRanges(std::vector<int> inputRange)
{
    sort(inputRange.begin(), inputRange.end());
    
    int totalReadings = 0;
    while (inputRange.size() > totalReadings)
    {
        int element = inputRange[totalReadings];
        int startRangeValue = element;
        int occurence = 0;
        int rangeReadings = 0;
        while (occurence = std::count(inputRange.begin(), inputRange.end(), element))
        {
            rangeReadings += occurence;
            ++element;
        }
        totalReadings += rangeReadings;
        std::string rangeWithReading = to_string(startRangeValue) + "-" + to_string(element - 1) + "," + to_string(rangeReadings);
        m_cacheRange.push_back(rangeWithReading);
        rangeReadings = 0;
    }
}

void FindRangeReadings::printRangeandReadings()
{
    std::cout << "Range , Readings" << endl;
    for (cacheRages::iterator itr = m_cacheRange.begin(); itr != m_cacheRange.end(); itr++)
    {
        std::cout << *itr <<endl;
    }
}