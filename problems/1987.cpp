#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const long long MOD = 1e9 + 7;

    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.size();
        long long o = 0;
        long long z = 0;
        long long ans = 1;
        long long zero = 0;
        for(char& c : binary){
            if(c == '1'){
                long long add = (ans - o - zero + MOD) % MOD;
                ans += add;
                ans %= MOD;
                o += add;
                o %= MOD;
            }else{
                long long add = (ans - z - zero + MOD) % MOD;
                ans += add;
                ans %= MOD;
                z += add;
                z %= MOD;
                zero = 1;
            }
        }
        return (ans - 1 + MOD) % MOD;
    }
};