#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long MOD = 1e9 + 7;

    int distinctSubseqII(string s) {
        vector<long long> dp (26,0);
        long long ans = 1;
        for(auto& c : s){
            long long x = (ans - dp[c - 'a'] + MOD) % MOD;
            dp[c - 'a'] += x;
            dp[c - 'a'] %= MOD;
            ans += x;
            ans %= MOD;
        }
        return (ans - 1 + MOD) % MOD;
    }
};