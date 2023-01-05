// LeetCode Link-https://leetcode.com/problems/course-schedule/submissions/868594271/

// Approach-

// step1- create a adjacency list-
//          (an adjacency list is a collection of unordered lists used to representfinite graph. Each unordered
//           list within an adjacency list describes the set of neighbors of a particular vertex in the graph).

// step2- Apply topological sort on the graph.
//          (a topological sort is a graph traversal in which each node v is visited only after all its
//           dependencies are visited).

// step3- After applying topological sort if the nodes visited in topological sort is equal to the number of
//          nodes in graph,then we can finish all scheduled course otherwise we can't.

// The Time complexity of above approach is-O(V+E)
//      where V is the no of vertex and E is the no of edges.
// Space Complexity-O(|V|)

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