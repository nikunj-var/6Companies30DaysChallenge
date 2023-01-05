// LeetCode link-https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/870515795/

// Approach-
// create a duplicate vector called dupnums ,the main use of this duplicate vector is-
//      we sort the duplicate vector, then compare duplicate vector with original vector and store the indices
//      of those whose elements who are out of their places.
//      and then find the shortest length of the unsorted contiguous subarray.
// to store indices use two pointers which keep track of the subarray.

// The Time complexity of above approach is-O(n)
//      because we travel the array once
// Space Complexity-O(n)
//      because we store the original vector into duplicate vector
// n, is the length of vector
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