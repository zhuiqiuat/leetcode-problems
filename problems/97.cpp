#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(s3.size() != n + m){
            return false;
        }
        bool dp[m + 1];
        memset(dp,0,sizeof(dp));
        dp[0] = true;
        for(int i = 1;i <= m;i++){
            if(s2[i - 1] != s3[i - 1]){
                break;
            }
            dp[i] = true;
        }
        int x = n;
        for(int i = 1;i <= n;i++){
            if(s1[i - 1] != s3[i - 1]){
                x = i - 1;
                break;
            }
        }
        for(int i = 1;i <= n;i++){
            if(i == x + 1){
                dp[0] = false;
            }
            for(int j = 1;j <= m;j++){
                dp[j] = (s1[i - 1] == s3[i + j - 1] && dp[j]) || (s2[j - 1] == s3[i + j - 1] && dp[j - 1]);
            }
        }
        return dp[m];
    }
};