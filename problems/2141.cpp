#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool f(int n, vector<int>& batteries,int m){
        long long sum = 0;
        for(auto& x : batteries){
            if(x > m){
                n--;
            }else{
                sum += x;
            }
            if(sum >= ((long long) n) * m){
                return true;
            }
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        int mx = -1;
        for(auto& x : batteries){
            sum += x;
            mx = max(mx,x);
        }
        if(sum > ((long long) mx) * n){
            return sum / n;
        }
        int l = 0;
        int r = mx;
        long long ans = -1;
        while(l <= r){
            int m = l + ((r - l) >> 1);
            if(f(n,batteries,m)){
                ans = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return ans;
    }
};