#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n < m){
            return 0;
        }
        vector<unsigned long long> dp (m + 1);
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = m;j >= 1;j--){
                if(s[i - 1] == t[j - 1]){
                    dp[j] += dp[j - 1];
                }
            }
        }
        return (int) dp[m];
    }
};