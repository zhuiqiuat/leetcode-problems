#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int ans = 0;
        vector<vector<int>> graph (n + 5,vector<int> ());
        vector<int> cnt (n + 5,0);
        vector<int> dp (n + 5,0);
        for(auto& v : relations){
            graph[v[0]].push_back(v[1]);
            cnt[v[1]]++;
        }
        queue<int> q;
        for(int i = 1;i <= n;i++){
            if(cnt[i] == 0){
                q.push(i);
                dp[i] = time[i - 1];
            }
        }
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(auto& w : graph[now]){
                dp[w] = max(dp[w],time[w - 1] + dp[now]);
                cnt[w]--;
                if(cnt[w] == 0){
                    q.push(w);
                }
            }
            if(graph[now].size() == 0){
                ans = max(ans,dp[now]);
            }
        }
        return ans;
    }
};