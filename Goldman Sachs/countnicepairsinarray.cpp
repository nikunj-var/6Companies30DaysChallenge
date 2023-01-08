#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int reverse(int n){
        int rev = 0;
	
	// The magic happens here :P
	while ( n != 0 ){
		// Multiply rev by 10.
		rev = rev * 10;
		
		// Add n modulus 10 to rev.
		rev = rev + (n % 10);
		
		// Divide n by 10.
		n = n / 10;
	}
    return rev;
    }
    int countNicePairs(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp(nums.size());
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i] - reverse(nums[i])) != mp.end()){
                ans=(ans+mp[nums[i] - reverse(nums[i])])%1000000007;
            }
                mp[nums[i] - reverse(nums[i])]++;
        }

        return ans%1000000007;
    }
};