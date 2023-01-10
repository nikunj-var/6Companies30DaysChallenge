#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> output;
    void solve(int numarrows, vector<int> &alicearrows, int sum, int &maxsum, int ind, vector<int> ans)
    {
        if (numarrows == 0 || ind < 0)
        {
            if (maxsum < sum)
            {
                maxsum = sum;
                output = ans;
            }
            return;
        }

        if (ind == 0)
        {
            ans[ind] = numarrows;
            solve(0, alicearrows, sum + ind, maxsum, ind - 1, ans);
            ans[ind] = 0;
            return;
        }
        else if (numarrows >= alicearrows[ind] + 1)
        {
            ans[ind] = alicearrows[ind] + 1;
            solve(numarrows - (alicearrows[ind] + 1), alicearrows, sum + ind, maxsum, ind - 1, ans);
            ans[ind] = 0;
        }
        solve(numarrows, alicearrows, sum, maxsum, ind - 1, ans);
    }
    vector<int> maximumBobPoints(int numarrows, vector<int> &alicearrows)
    {
        vector<int> ans(12, 0);
        int sum = 0;
        int maxsum = 0;
        solve(numarrows, alicearrows, sum, maxsum, 11, ans);
        return output;
    }
};