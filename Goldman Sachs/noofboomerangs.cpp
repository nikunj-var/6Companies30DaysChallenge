#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int n = points.size();

        if (n == 1)
            return 0;

        int total = 0;

        for (int i = 0; i < n; i++)
        {

            map<int, int> mp;

            for (int j = 0; j < n; j++)
            {

                // in beginning hume kisi bhi point se ye dekhna hai ki kitne points tak ka distance us point se same hai
                // and the formula to find the distance between two points is √ (x2-x2)^2 + (y2-y2)^2.
                // then hum har point ke liye baki sare points ke distance nikalenge or distance ko map me store kr lenge.
                // we have to make a new map for each point.

                int distance = ((points[i][0] - points[j][0]) * (points[i][0] - points[j][0])) + ((points[i][1] - points[j][1]) * (points[i][1] - points[j][1]));
                mp[distance]++;
            }

            for (auto noofboom : mp)
            {

                // here what i do is
                // suppose there are 3 points whose distances are same from one point then we can make n*(n-1) combinations for that point. for ex-
                // point from where we find distance is -> 1
                // and the points whose distance is same from that point is 2, 3, 4.
                // then the combination of i ,j ,k is
                // 1 - 2 - 3
                // 1 - 3 - 2
                // 1 - 2 - 4
                // 1 - 4 - 2
                // 1 - 3 - 4
                // 1 - 4 - 3
                // that's why we do total += n*(n-1);

                total += (noofboom.second) * (noofboom.second - 1);
            }
        }
        return total;
    }
};