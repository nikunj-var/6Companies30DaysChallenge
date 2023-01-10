#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<int> dp(n + 1, 0);
        long noOfpeoplesharingsecret = 0;
        long ans = 0;
        dp[1] = 1;
        long mod = 1000000007;
        for (int i = 2; i <= n; i++)
        {
            long noofnewpeoplesharesecret = dp[max(i - delay, 0)] % mod;
            long noofpeopleforget = dp[max(i - forget, 0)] % mod;

            noOfpeoplesharingsecret = (noOfpeoplesharingsecret + noofnewpeoplesharesecret - noofpeopleforget + mod) % mod;

            dp[i] = noOfpeoplesharingsecret % mod;
        }
        for (int i = n - forget + 1; i <= n; i++)
        {
            ans = (ans + dp[i]) % mod;
        }
        return (int)ans % mod;
    }
};