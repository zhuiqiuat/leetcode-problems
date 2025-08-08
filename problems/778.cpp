#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct point {
        int x,y;
        int w;
    };
    struct cmp {
        bool operator() (point p1,point p2){
            return p1.w > p2.w;
        }
    };

    bool vist[60][60] = {0};
    int dir[8][2] = {1,0,0,1,-1,0,0,-1,-1,-1,-1,1,1,-1,1,1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<point,vector<point>,cmp> pq;
        pq.emplace(0,0,grid[0][0]);
        while(pq.size()){
            point now = pq.top();
            pq.pop();
            if(now.x == n - 1 && now.y == n - 1){
                return now.w;
            }
            if(vist[now.x][now.y]) continue;
            vist[now.x][now.y] = true;
            for(int i = 0;i < 4;i++){
                int x = now.x + dir[i][0];
                int y = now.y + dir[i][1];
                if(x >= 0 && x < n && y >= 0 && y < n && !vist[x][y]){
                    pq.emplace(x,y,max(now.w,grid[x][y]));
                }
            }
        }
        return -1;
    }
};