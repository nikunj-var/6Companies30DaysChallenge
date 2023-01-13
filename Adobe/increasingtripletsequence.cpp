#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {

        int start = INT_MAX, mid = INT_MAX, end = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= start)
                start = nums[i];

            else if (nums[i] < mid)
                mid = nums[i];

            else if (nums[i] > mid && nums[i] <= end)
            {
                end = nums[i];
                return true;
            }
        }
        return false;
    }
};