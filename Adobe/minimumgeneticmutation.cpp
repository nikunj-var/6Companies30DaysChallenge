#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <queue>
using namespace std;

class Solution
{
public:
    int minMutation(string startgene, string endgene, vector<string> &bank)
    {
        unordered_set<string> st{bank.begin(), bank.end()};

        if (!st.count(endgene))
        {
            return -1;
        }

        queue<string> q;

        q.push(startgene);
        int steps = 0, s;
        string curr, t;

        while (!q.empty())
        {
            s = q.size();
            while (s--)
            {
                curr = q.front();
                q.pop();
                if (curr == endgene)
                    return steps;
                st.erase(curr);
                for (int i = 0; i < 8; i++)
                {
                    t = curr;
                    t[i] = 'A';
                    if (st.count(t) != 0)
                    {
                        q.push(t);
                    }
                    t[i] = 'C';
                    if (st.count(t) != 0)
                    {
                        q.push(t);
                    }
                    t[i] = 'G';
                    if (st.count(t) != 0)
                    {
                        q.push(t);
                    }
                    t[i] = 'T';
                    if (st.count(t) != 0)
                    {
                        q.push(t);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};