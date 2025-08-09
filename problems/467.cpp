#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    char f(char c){
        if(c == 'a'){
            return 'z';
        }else{
            return c - 1;
        }
    }

    int findSubstringInWraproundString(string s) {
        int n = s.size();
        int cnt[26] = {0};
        vector<int> dp (n,1);
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(i - 1 >= 0 && f(s[i]) == s[i - 1]){
                dp[i] += dp[i - 1];
            }
            cnt[s[i] - 'a'] = max(cnt[s[i] - 'a'],dp[i]);
        }
        for(auto& x : cnt){
            ans += x;
        }
        return ans;
    }
};