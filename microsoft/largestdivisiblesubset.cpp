// LeetCode link-https://leetcode.com/problems/largest-divisible-subset/submissions/871734039/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        int maximum = INT_MIN, maximumindex;
        vector<int> greater(nums.size(), 0);
        vector<int> parent(nums.size(), 0);
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] % nums[i] == 0 && greater[i] < 1 + greater[j])
                {
                    greater[i] = 1 + greater[j];
                    parent[i] = j;
                    if (maximum < greater[i])
                    {
                        maximum = greater[i];
                        maximumindex = i;
                    }
                }
            }
        }
        for (int i = 0; i < maximum; i++)
        {
            ans.push_back(nums[maximumindex]);
            maximumindex = parent[maximumindex];
        }
        return ans;
    }
};