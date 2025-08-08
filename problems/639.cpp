#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long dp[100005];

    const long long MOD = 1e9 + 7;

    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        int n = s.size();
        for(int i = 0;i < n;i++){
            dp[i] = 0;
        }
        dp[n] = 1;
        for(int i = n - 1;i >= 0;i--){
            if(s[i] == '0'){
                continue;
            }
            if(s[i] != '*'){
                if(i + 2 <= n){
                    if(s[i + 1] != '*'){
                        if(s.substr(i,2) <= "26"){
                            dp[i] += dp[i + 2];
                        }
                    }else{
                        if(s[i] == '1'){
                            dp[i] += 9 * dp[i + 2];
                        }else if(s[i] == '2'){
                            dp[i] += 6 * dp[i + 2];
                        }
                    }
                }
                dp[i] += dp[i + 1];
                dp[i] %= MOD;
            }else{
                if(i + 2 <= n){
                    if(s[i + 1] != '*'){
                        if(s[i + 1] <= '6'){
                            dp[i] += 2 * dp[i + 2];
                        }else{
                            dp[i] += dp[i + 2];
                        }
                    }else{
                        dp[i] += 15 * dp[i + 2];
                    }
                }
                dp[i] += 9 * dp[i + 1];
                dp[i] %= MOD;
            }
        }
        return dp[0];
    }
};