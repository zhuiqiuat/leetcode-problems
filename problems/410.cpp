#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int f(vector<int>& nums, int m){
        int p = 1;
        int sum = 0;
        for(auto& x : nums){
            if(x > m){
                return INT_MAX;
            }
            if(sum + x > m){
                p++;
                sum = x;
            }else{
                sum += x;
            }
        }
        return p;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for(auto& x : nums){
            sum += x;
        }
        int l = 0;
        int r = sum;
        int ans = INT_MAX;
        while(l <= r){
            int m = l + ((r - l) >> 1);
            if(f(nums,m) <= k){
                r = m - 1;
                ans = min(ans,m);
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};