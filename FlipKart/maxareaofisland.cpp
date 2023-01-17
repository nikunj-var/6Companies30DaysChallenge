#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;

        return 1 + solve(i + 1, j, grid) + solve(i - 1, j, grid) + solve(i, j + 1, grid) + solve(i, j - 1, grid);
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans = max(ans, solve(i, j, grid));
                }
            }
        }
        return ans;
    }
};