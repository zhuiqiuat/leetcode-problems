#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n + 1];
        dp[1] = 1;
        int x = 1;
        int y = 1;
        int z = 1;
        for(int i = 2;i <= n;i++){
            int a = dp[x] * 2;
            int b = dp[y] * 3;
            int c = dp[z] * 5;
            int cur = min({a,b,c});
            if(cur == a){
                x++;
            }
            if(cur == b){
                y++;
            }
            if(cur == c){
                z++;
            }
            dp[i] = cur;
        }
        return dp[n];
    }
};