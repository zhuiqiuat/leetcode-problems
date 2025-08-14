#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[m + 1];
        for(int i = 0;i <= m;i++){
            dp[i] = i;
        }
        int bak,lup;
        for(int i = 1;i <= n;i++){
            dp[0] = i;
            lup = i - 1;
            for(int j = 1;j <= m;j++){
                bak = dp[j];
                if(word1[i - 1] == word2[j - 1]){
                    dp[j] = lup;
                }else{
                    dp[j] = min({dp[j],dp[j - 1],lup}) + 1;
                }
                lup = bak;
            }
        }
        return dp[m];
    }
};