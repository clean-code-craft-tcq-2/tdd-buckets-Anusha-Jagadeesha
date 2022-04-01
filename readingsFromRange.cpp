#include "readingsFromRange.h"
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cfenv>
#include <climits>

using namespace std;

void FindRangeReadings::findandStoreReadingsFromRanges(std::vector<int> inputRange)
{
    bool isInputRangeIsWithinRange = sortInputRange(inputRange);
    
    int totalReadings = 0;
    while ((inputRange.size() > totalReadings) && (isInputRangeIsWithinRange))
    {
        int element = inputRange[totalReadings];
        int startRangeValue = element;
        int occurence = 0;
        int rangeReadings = 0;
        while (occurence = std::count(inputRange.begin(), inputRange.end(), element))
        {
            int temp_a2d = 0;
            rangeReadings += occurence;
            temp_a2d = convertToAmps(element);
            m_currentSamplesAfterA2D.push_back(temp_a2d);
            ++element;
        }
        totalReadings += rangeReadings;
        std::string rangeWithReading = to_string(startRangeValue) + "-" + to_string(element - 1) + "," + to_string(rangeReadings);
        m_storeRange.push_back(rangeWithReading);
        rangeReadings = 0;
    }
}

bool sortInputRange(std::vector<int> inputRange)
{
    sort(inputRange.begin(), inputRange.end());
    for(int i = 0; i < inputRange.size(); i++)
    {
        if((inputRange[i] < 0) || (inputRange[i] > 4094))
        {
            cout << "invalid range" << endl;
            return false;
        }
        return true;
    }
}

int convertToAmps(int currentElements)
{
    float ConvertToAmp = (float( 10 * currentElements) / 4094);
    return round(ConvertToAmp);
}

void FindRangeReadings::printRangeandReadings()
{
    std::cout << "Range , Readings" << endl;
    for (storeRanges::iterator itr = m_storeRange.begin(); itr != m_storeRange.end(); itr++)
    {
        std::cout << *itr <<endl;
    }
}
