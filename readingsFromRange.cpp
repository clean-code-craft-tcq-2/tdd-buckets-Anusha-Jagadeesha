#include "readingsFromRange.h"
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;
std::string storeInMap[5];

std::string* getReadingsFromRanges(std::vector<int> inputRange)
{
    int readings = 0;
    int previousValue = inputRange[0];
    int startRangeValue;

    sort(inputRange.begin(), inputRange.end());

    for (int i = 0; inputRange.size() > i; i++)
    {
        if (((previousValue == inputRange[i]) || ((previousValue + 1) == inputRange[i])) && (i != ((inputRange.size())-1)))
        {
            ++readings;
            previousValue = inputRange[i];
            if (readings == 1)
            {
                startRangeValue = inputRange[i];
            }
        }
        else
        {
            if(i == ((inputRange.size())-1))
            {
                ++readings;
                previousValue = inputRange[i];
            }
            for(int j = 0; j < inputRange.size(); j++)
            {
            storeInMap[i] = to_string(startRangeValue) + "-" + to_string(previousValue) + "," + to_string(readings);
            }
            readings = 1;
            previousValue = inputRange[i];
            startRangeValue = inputRange[i];
        }
    }
    return storeInMap;
}