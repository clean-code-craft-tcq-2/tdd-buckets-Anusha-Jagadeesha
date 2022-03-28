#include <stdio.h>
#include <string>
using namespace std;
#include <map>
#include <vector>

typedef std::vector<std::string> cacheRages;
typedef std::vector<int> storeConvertedCurrentSamples;

class FindRangeReadings
{
public:
    cacheRages m_cacheRange;
    storeConvertedCurrentSamples m_currentSamplesAfterA2D;
    void cacheReadingsFromRanges(std::vector<int> inputRange);
    void printRangeandReadings();
    int convertToAmps(int currentElements);
    bool sortInputRange(std::vector<int> inputRange);
};
