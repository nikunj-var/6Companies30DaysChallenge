#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> dupnums;
        dupnums = nums;
        sort(dupnums.begin(), dupnums.end());
        int low = INT_MAX, high = INT_MIN;
        if (nums == dupnums)
            return 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != dupnums[i])
            {
                low = min(low, i);
                high = max(high, i);
            }
        }
        return high - low + 1;
    }
};