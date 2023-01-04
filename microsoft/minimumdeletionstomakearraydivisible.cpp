// LeetCode link-https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/submissions/871108251/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = nums.size();
        int m = numsDivide.size();
        for (int i = 0; i < n; i++)
        {
            q.push(nums[i]);
        }
        sort(numsDivide.begin(), numsDivide.end());
        int ans = 0;
        while (!q.empty())
        {
            int top = q.top();
            int count = 0;
            q.pop();
            for (int i = 0; i < m; i++)
            {
                if (numsDivide[i] % top != 0)
                {
                    ans++;
                    while (!q.empty() && q.top() == top)
                    {
                        ans++;
                        q.pop();
                    }
                    break;
                }
                else
                    count++;
            }
            if (count == m)
                break;
        }
        return (ans == n) ? -1 : ans;
    }
};