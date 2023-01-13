#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

class Solution
{
public:
    bool solve(string str1, string str2)
    {
        int i = 0;
        for (int k = 0; k < str2.size(); k++)
        {
            if (str1[i] == str2[k])
            {
                i++;
            }
            if (str1.length() == i)
            {
                return true;
            }
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string> &words)
    {
        unordered_map<string, int> mp;
        int ans = 0;
        for (auto it : words)
        {
            mp[it]++;
        }
        for (auto it : mp)
        {
            if (solve(it.first, s))
            {
                ans += it.second;
            }
        }
        return ans;
    }
};