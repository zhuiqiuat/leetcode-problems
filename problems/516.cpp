#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n];
        int a,b;
        for(int i = n - 1;i >= 0;i--){
            dp[i] = 1;
            a = 1;
            if(i + 1 < n){
                dp[i + 1] = s[i] == s[i + 1] ? 2 : 1;
            }
            for(int j = i + 2;j < n;j++){
                b = dp[j];
                if(s[i] == s[j]){
                    dp[j] = a + 2;
                }else{
                    dp[j] = max(dp[j],dp[j - 1]);
                }
                a = b;
            }
        }
        return dp[n - 1];
    }
};