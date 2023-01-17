#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        vector<pair<int, string>> temp;
        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i]]++;
        }
        priority_queue<pair<int, string>> q;
        for (auto it : mp)
        {
            q.push({-it.second, it.first});
            if (q.size() > k)
            {
                q.pop();
            }
        }

        while (!q.empty())
        {
            temp.push_back(q.top());
            q.pop();
        }
        sort(temp.begin(), temp.end());
        vector<string> ans;
        for (int i = 0; i < temp.size(); i++)
        {
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};