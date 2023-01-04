// LeetCode link-https://leetcode.com/problems/rotate-function/submissions/871119472/

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