#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dir[4][2] = {-1,0,0,-1,1,0,0,1};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp (n,vector<int> (m));
        vector<vector<int>> cnt (n,vector<int> (m));
        int ans = 1;
        queue<pair<int,int>> q;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                for(int k = 0;k < 4;k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(x >= 0 && x < n && y >= 0 && y < m){
                        if(matrix[i][j] > matrix[x][y]){
                            cnt[x][y]++;
                        }
                    }
                }
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(cnt[i][j] == 0){
                    q.push({i,j});
                    dp[i][j] = 1;
                }
            }
        }
        while(q.size()){
            int s = q.size();
            while(s--){
                pair<int,int> now = q.front();
                q.pop();
                for(int k = 0;k < 4;k++){
                    int x = now.first + dir[k][0];
                    int y = now.second + dir[k][1];
                    if(x >= 0 && x < n && y >= 0 && y < m){
                        if(matrix[now.first][now.second] > matrix[x][y]){
                            if(--cnt[x][y] == 0){
                                dp[x][y] = dp[now.first][now.second] + 1;
                                ans = max(ans,dp[x][y]);
                                q.push({x,y});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};