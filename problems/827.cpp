#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int dp[250000] = {0};

    void dfs(vector<vector<int>>& grid,int i,int j,int now){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || grid[i][j] != 1) return;
        grid[i][j] = now;
        dp[now]++;
        dfs(grid,i + 1,j,now);
        dfs(grid,i - 1,j,now);
        dfs(grid,i,j + 1,now);
        dfs(grid,i,j - 1,now);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ma = -1;
        int now = 2;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 0) continue;
                dfs(grid,i,j,now);
                ma = max(ma,dp[now++]);
            }
        }
        
        bool vist[now];
        memset(vist,0,sizeof(vist));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] != 0) continue;
                int cnt = 0;
                int up = i - 1 >= 0 ? grid[i - 1][j] : 0;
                int down = i + 1 < n ? grid[i + 1][j] : 0;
                int left = j - 1 >= 0 ? grid[i][j - 1] : 0;
                int right = j + 1 < n ? grid[i][j + 1] : 0;
                cnt += 1 + dp[up];
                vist[up] = true;
                if(!vist[down]){
                    cnt += dp[down];
                    vist[down] = true;
                }
                if(!vist[left]){
                    cnt += dp[left];
                    vist[left] = true;
                }
                if(!vist[right]){
                    cnt += dp[right];
                    vist[right] = true;
                }
                vist[up] = vist[down] = vist[left] = vist[right] = false;
                ma = max(ma,cnt);
            }
        }
        return ma;
    }
};