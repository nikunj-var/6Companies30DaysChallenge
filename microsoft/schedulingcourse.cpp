// LeetCode Link-https://leetcode.com/problems/course-schedule/submissions/868594271/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &arr)
    {
        vector<int> adj[n];
        for (int i = 0; i < arr.size(); i++)
        {
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        vector<int> topo;
        vector<int> indegree(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for (auto j : adj[i])
            {
                indegree[j]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!indegree[i])
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto neighbour : adj[node])
            {
                indegree[neighbour]--;
                if (!indegree[neighbour])
                {
                    q.push(neighbour);
                }
            }
        }
        return topo.size() == n;
    }
};