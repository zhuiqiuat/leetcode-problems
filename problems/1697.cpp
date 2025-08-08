#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dsu[100050] = {0};
    void build(int n){
        for(int i = 1;i <= n;i++){
            dsu[i] = i;
        }
    }

    int find(int n){
        queue<int> q;
        while(n != dsu[n]){
            q.push(n);
            n = dsu[n];
        }
        while(!q.empty()){
            dsu[q.front()] = n;
            q.pop();
        }
        return n;
    }

    void uni(int a,int b){
        int fa = find(a);
        int fb = find(b);
        if(fa != fb){
            dsu[fa] = fb;
        }
    }

    struct bian {
        int v,w;
        int c;
    };

    struct quer {
        int ind;
        int v,w;
        int limit;
    };
    
    static bool cmp5(bian b1,bian b2){
        return b1.c < b2.c;
    }
    
    static bool cmp2(quer q1,quer q2){
        return q1.limit < q2.limit;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> edgeList, vector<vector<int>>& queries) {
        build(n);
        vector<bian> bians;
        for(int i = 0;i < edgeList.size();i++){
            bians.push_back({edgeList[i][0],edgeList[i][1],edgeList[i][2]});
        }
        sort(bians.begin(),bians.end(),cmp5);
        vector<quer> qs;
        vector<bool> ans (queries.size(),0);
        for(int i = 0;i < queries.size();i++){
            vector<int> now = queries[i];
            qs.push_back({i,now[0],now[1],now[2]});
        }
        sort(qs.begin(),qs.end(),cmp2);
        int j = 0;
        for(int i = 0;i < bians.size();i++){
            if(j < qs.size() && bians[i].c >= qs[j].limit){
                while(j < qs.size() && qs[j].limit <= bians[i].c){
                    if(find(qs[j].v) == find(qs[j].w)){
                        ans[qs[j].ind] = true;
                    }
                    j++;
                }
            }
            if(find(bians[i].v) != find(bians[i].w)){
                uni(bians[i].v,bians[i].w);
            }
        }
        while(j < qs.size()){
            if(find(qs[j].v) == find(qs[j].w)){
                ans[qs[j].ind] = true;
            }
            j++;
        }
        return ans;
    }
};