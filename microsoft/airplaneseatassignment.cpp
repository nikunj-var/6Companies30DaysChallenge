// LeetCode link- https://leetcode.com/problems/airplane-seat-assignment-probability/submissions/869044650/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    double nthPersonGetsNthSeat(int n)
    {
        if (n == 1)
            return 1.00000;
        return 0.50000;
    }
};