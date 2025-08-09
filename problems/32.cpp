#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp (n,0);
        int ans = 0;
        for(int i = 1;i < n;i++){
            if(s[i] == '('){
                continue;
            }
            int l = i - dp[i - 1] - 1;
            if(l >= 0 && s[l] == '('){
                dp[i] = dp[i - 1] + 2 + (l - 1 >= 0 ? dp[l - 1] : 0);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};