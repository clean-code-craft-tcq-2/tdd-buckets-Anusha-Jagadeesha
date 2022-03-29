#include <stdio.h>
#include <string>
using namespace std;
#include <map>
#include <vector>

typedef std::vector<std::string> storeRages;
typedef std::vector<int> storeConvertedCurrentSamples;

class FindRangeReadings
{
public:
    storeRages m_storeRange;
    storeConvertedCurrentSamples m_currentSamplesAfterA2D;
    void cacheReadingsFromRanges(std::vector<int> inputRange);
    void printRangeandReadings();
    int convertToAmps(int currentElements);
    bool sortInputRange(std::vector<int> inputRange);
};
