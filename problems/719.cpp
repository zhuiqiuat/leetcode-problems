#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long
    #define ull unsigned long long
    #define fr first
    #define sc second
    #define sz(x) (x).size()
    #define all(a) (a).begin(),(a).end()
    #define srt(a) sort(all(a));
    #define MX(a) *max_element(all(a));
    #define MN(a) *min_element(all(a));

    int f(vector<int>& nums, int d){
        int cnt = 0;
        for(int i = 0;i < sz(nums);i++){
            int ind1,ind2;
            int l1,l2,r1,r2;
            l1 = l2 = 0;
            r1 = r2 = sz(nums) - 1;
            int x1 = nums[i] + d;
            while(l1 <= r1){
                int m = l1 + ((r1 - l1) >> 1);
                if(nums[m] <= x1){
                    l1 = m + 1;
                    ind1 = m;
                }else{
                    r1 = m - 1;
                }
            }
            cnt += ind1 - i;
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        srt(nums);
        int n = sz(nums);
        int l = 0;
        int r = nums[n - 1] - nums[0];
        int ans = -1;
        while(l <= r){
            int m = l + ((r - l) >> 1);
            if(f(nums,m) >= k){
                r = m - 1;
                ans = m;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};