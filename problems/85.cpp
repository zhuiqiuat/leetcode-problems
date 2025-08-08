#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int st[205];
    int x;

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = -1;
        vector<int> dp (m,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                dp[j] = matrix[i][j] == '0' ? 0 : dp[j] + 1;
            }
            x = 0;
            for(int j = 0;j < m;j++){
                while(x > 0 && dp[st[x - 1]] >= dp[j]){
                    int ind = st[--x];
                    int l = x > 0 ? st[x - 1] : -1;
                    int r = j;
                    ans = max(ans,(r - l - 1) * dp[ind]);
                }
                st[x++] = j;
            }
            while(x > 0){
                int ind = st[--x];
                int l = x > 0 ? st[x - 1] : -1;
                int r = m;
                ans = max(ans,(r - l - 1) * dp[ind]);
            }
        }
        return ans;
    }
};