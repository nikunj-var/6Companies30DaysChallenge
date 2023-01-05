// LeetCode link-https://leetcode.com/problems/rotate-function/submissions/871119472/

// Approach-

// step1- create two variables sum,sum1-
//         sum is used to store the sum of all values in vector.
//         sum1 is used to store the sum of all values*indices in the vector.

// step2- Traverse the vector from ending

// step3- For each index, do sum1 += sum - (nums[i] * n);
//          and store the maximum value in ans variable.

// The Time complexity of above approach is-O(n)
//      where, n is the size of vector.
// Space Complexity-O(1)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        int ans = 0;
        int sum = 0;
        int sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum1 += (i * nums[i]);
        }
        ans = sum1;
        for (int i = n - 1; i >= 0; i--)
        {
            sum1 += sum - (nums[i] * n);
            ans = max(sum1, ans);
        }
        return ans;
    }
};