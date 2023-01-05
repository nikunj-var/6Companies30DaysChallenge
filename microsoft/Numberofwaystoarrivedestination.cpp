// Leetcode Link-https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

// Approach- Dijkstra Algorithm
// Time Complexity-O(V^2)
// Space Complexity-O(V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int noofshortestpath(vector<vector<pair<long long, long long>>> &adj, int src, int n)
    {
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
            {
                continue;
            }
            for (auto [v, time] : adj[u])
            {
                if (dist[v] > d + time)
                {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if (dist[v] == d + time)
                {
                    ways[v] = (ways[u] + ways[v]) % 1000000007;
                }
            }
        }
        return ways[n - 1];
    }
    int countPaths(int n, vector<vector<int>> &roads)
    {
        if (n == 2)
            return 1;

        vector<vector<pair<long long, long long>>> adj(n);
        for (int i = 0; i < roads.size(); i++)
        {
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long time = roads[i][2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        return noofshortestpath(adj, 0, n);
    }
};