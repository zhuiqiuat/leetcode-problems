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

    int f(int n,int m,int x){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            ans += min(x / i,m);
        }
        return ans;
    }

    int findKthNumber(int n, int m, int k) {
        int l = 1;
        int r = n * m;
        int ans = -1;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            if(f(n,m,mid) >= k){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};