#include <stdio.h>
#include <string>
using namespace std;
#include <map>
#include <vector>

typedef std::vector<std::string> storeRanges;
typedef std::vector<int> storeConvertedCurrentSamples;

class FindRangeReadings
{
public:
    storeRanges m_storeRange;
    storeConvertedCurrentSamples m_currentSamplesAfterA2D;
    void findandStoreReadingsFromRanges(std::vector<int> inputRange);
    void printRangeandReadings();
};

    int convertToAmps(int currentElements);
    bool sortInputRange(std::vector<int> inputRange);
