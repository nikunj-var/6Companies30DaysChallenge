// LeetCode link-https://leetcode.com/problems/bulls-and-cows/submissions/868442941/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int cows = 0;
        int bulls = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                m[secret[i]]++;
            }
        }
        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] != guess[i] && m[guess[i]])
            {
                cows++;
                m[guess[i]]--;
            }
        }
        return (to_string(bulls) + 'A' + to_string(cows) + 'B');
    }
};