// LeetCode Link-https://leetcode.com/problems/most-profitable-path-in-a-tree/submissions/871211897/

// Approach-

// step1- create a adjacency list-
//          (an adjacency list is a collection of unordered lists used to representfinite graph. Each unordered
//           list within an adjacency list describes the set of neighbors of a particular vertex in the graph).

// step2- Find parent and distance of each vertex using dfs.

// step3- For vector, amount divide the amount of the index at which bob and alice come together.

// step4- traverse the graph using dfs and find the maxamount.

// The Time complexity of above approach is-O(V+E)
//      where V is the no of vertex and E is the no of edges.
// Space Complexity-O(|V|)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int ans = 0;
    int maxans = INT_MIN;
    void dfsfindparent(vector<int> adj[], vector<int> &dist, vector<int> &parent, int curr, int currdistance, int currparent)
    {
        dist[curr] = currdistance;
        parent[curr] = currparent;
        for (auto neighbour : adj[curr])
        {
            if (currparent == neighbour)
            {
                continue;
            }
            dfsfindparent(adj, dist, parent, neighbour, currdistance + 1, curr);
        }
    }
    void dfs(vector<int> adj[], vector<int> &visited, vector<int> &amount, int curr)
    {
        visited[curr] = true;
        ans += amount[curr];
        int trav = 0;
        for (auto node : adj[curr])
        {
            if (!visited[node])
            {
                trav++;
                dfs(adj, visited, amount, node);
            }
            else
            {
                continue;
            }
        }
        if (trav == 0)
        {
            maxans = max(ans, maxans);
        }
        ans -= amount[curr];
    }
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = edges.size();
        vector<int> adj[n + 1];
        vector<int> dist(n + 1, -1);
        vector<int> parent(n + 1, -1);
        vector<int> visited(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfsfindparent(adj, dist, parent, 0, 0, 0);
        int curr = bob;
        int currdistance = 0;
        while (curr != 0)
        {
            if (dist[curr] > currdistance)
            {
                amount[curr] = 0;
            }
            else if (dist[curr] == currdistance)
            {
                amount[curr] /= 2;
            }
            curr = parent[curr];
            currdistance++;
        }
        dfs(adj, visited, amount, 0);
        return maxans;
    }
};