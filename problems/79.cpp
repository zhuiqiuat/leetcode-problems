#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    bool vist[6][6] = {0};

    int n,m;
    vector<vector<char>> board;
    string word;

    bool dfs(int dep,int x,int y){
        if(dep == word.size()){
            return true;
        }
        bool ans = false;
        for(int i = 0;i < 4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vist[nx][ny] && word[dep] == board[nx][ny]){
                vist[nx][ny] = true;
                ans = dfs(dep + 1,nx,ny);
                vist[nx][ny] = false;
                if(ans){
                    break;
                }
            }
        }
        return ans;
    }

    bool exist(vector<vector<char>>& grid, string s) {
        board = grid;
        word = s;
        n = grid.size();
        m = grid[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j] == word[0]){
                    vist[i][j] = true;
                    if(dfs(1,i,j)){
                        return true;
                    }
                    vist[i][j] = false;
                }
            }
        }
        return false;
    }
};