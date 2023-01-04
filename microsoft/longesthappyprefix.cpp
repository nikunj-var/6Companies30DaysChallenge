// LeetCode Link-https://leetcode.com/problems/longest-happy-prefix/submissions/869069357/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.length();
        if (n == 0)
            return "";

        int i = 0;
        int j = 1;
        vector<int> prefix(n, 0);

        while (j < n)
        {

            if (s[i] == s[j])
            {
                prefix[j] = i + 1;
                i++;
                j++;
            }
            else
            {
                if (i == 0)
                {
                    j++;
                }
                else
                {
                    i = prefix[i - 1];
                }
            }
        }
        return s.substr(0, i);
    }
};