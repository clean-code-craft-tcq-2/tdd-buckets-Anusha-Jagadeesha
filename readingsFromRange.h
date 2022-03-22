#include <stdio.h>
#include <string>
using namespace std;
#include <map>
#include <vector>

typedef std::vector<std::string> cacheRages;

class FindRangeReadings
{
public:
    cacheRages m_cacheRange;
    void cacheReadingsFromRanges(std::vector<int> inputRange);
    void printRangeandReadings();
};
