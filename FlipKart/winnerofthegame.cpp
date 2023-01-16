#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        
        for(int i=0;i<n;i++)
			v[i] = i+1;         // Filling values in vector
        
        int prev=0;
        while(v.size()>1){
            int rot = (prev + k - 1)%v.size();  // Calculating position to delete from
            v.erase(v.begin() + rot);
            prev = rot;
        }
        
        return v[0];
    }
};