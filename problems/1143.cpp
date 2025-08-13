#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[1001];

    int longestCommonSubsequence(string text1, string text2) {
        string s1,s2;
        if(text1.size() < text2.size()){
            s1 = text2;
            s2 = text1;
        }else{
            s1 = text1;
            s2 = text2;
        }
        for(int i = 0;i <= s2.size();i++){
            dp[i] = 0;
        }
        int a = 0;
        int b = 0;
        for(int i = 1;i <= s1.size();i++){
            a = 0;
            for(int j = 1;j <= s2.size();j++){
                b = dp[j];
                if(s1[i - 1] == s2[j - 1]){
                    dp[j] = a + 1;
                }else{
                    dp[j] = max(dp[j],dp[j - 1]);
                }
                a = b;
            }
        }
        return dp[s2.size()];
    }
};