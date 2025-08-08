#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> sum (n + 1,vector<int> (m + 1,0));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                sum[i][j] = grid[i - 1][j - 1];
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        vector<vector<int>> v (n + 2,vector<int> (m + 2,0));
        bool ans = true;
        for(int i = 1;i + stampHeight - 1 <= n;i++){
            for(int j = 1;j + stampWidth - 1 <= m;j++){
                int x = i + stampHeight - 1;
                int y = j + stampWidth - 1;
                if(sum[x][y] + sum[i - 1][j - 1] - sum[x][j - 1] - sum[i - 1][y] == 0){
                    v[i][j]++;
                    v[i][y + 1]--;
                    v[x + 1][j]--;
                    v[x + 1][y + 1]++;
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                v[i][j] += v[i - 1][j] + v[i][j -  1] - v[i - 1][j - 1];
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(grid[i - 1][j - 1] == 1){
                    v[i][j] = 1;
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(v[i][j] == 0){
                    ans = false;
                }
            }
        }
        return ans;
    }
};