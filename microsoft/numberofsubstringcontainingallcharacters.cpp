// LeetCode link-https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/868959291/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int left = 0;
        int right = 0;
        int n = s.length() - 1;
        int count = 0;
        unordered_map<char, int> mp;
        while (right <= n)
        {
            mp[s[right]]++;
            while (mp['a'] && mp['b'] && mp['c'])
            {
                count += 1 + (n - right);
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return count;
    }
};