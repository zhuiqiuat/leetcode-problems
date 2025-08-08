#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int tree[6550][26] = {0};

    int pass[6550] = {0};

    int end[6550] = {0};

    int cnt = 1;

    void build(){
        for(int i = 1;i <= cnt;i++){
            for(int j = 0;j < 26;j++){
                tree[i][j] = 0;
            }
            pass[i] = 0;
            end[i] = 0;
        }
    }

    void insert(string s){
        int cur = 1;
        pass[cur]++;
        for(int i = 0;i < s.size();i++){
            int p = s[i] - 'a';
            if(tree[cur][p] == 0){
                tree[cur][p] = ++cnt;
            }
            cur = tree[cur][p];
            pass[cur]++;
        }
        end[cur]++;
    }

    int count(string s){
        int cur = 1;
        for(int i = 0;i < s.size();i++){
            int p = s[i] - 'a';
            if(tree[cur][p] == 0){
                return 0;
            }
            cur = tree[cur][p];
        }
        return pass[cur];
    }

    int find(string s){
        int cur = 1;
        for(int i = 0;i < s.size();i++){
            int p = s[i] - 'a';
            if(tree[cur][p] == 0){
                return 0;
            }
            cur = tree[cur][p];
        }
        return end[cur];
    }

    void erase(string s){
        int cur = 1;
        pass[cur]--;
        for(int i = 0;i < s.size();i++){
            int p = s[i] - 'a';
            if(--pass[tree[cur][p]] == 0){
                tree[cur][p] = 0;
                return;
            }
            cur = tree[cur][p];
        }
        end[cur]--;
    }

    vector<string> ans = vector<string> ();
    int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    bool vist[15][15] = {0};

    void dfs(vector<vector<char>>& board,string& s,int dep,int x,int y){
        if(dep >= 10){
            return;
        }
        if(count(s) == 0){
            return;
        }
        vist[x][y] = true;
        s.push_back(board[x][y]);
        if(find(s) > 0){
            ans.push_back(s);
            erase(s);
        }
        for(int i = 0;i < 4;i++){
            int nxtx = x + dir[i][0];
            int nxty = y + dir[i][1];
            if(nxtx >= 0 && nxtx < board.size() && nxty >= 0 && nxty < board[0].size() && !vist[nxtx][nxty]){
                dfs(board,s,dep + 1,nxtx,nxty);
            }
        }
        vist[x][y] = false;
        s.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        build();
        ans.clear();
        string now = "";
        
        int n = board.size();
        int m = board[0].size();

        for(auto& s : words){
            insert(s);
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(count(now + board[i][j]) == 0) continue;
                dfs(board,now,0,i,j);
            }
        }

        return ans;
    }
};