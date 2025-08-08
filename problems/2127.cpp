#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const static int MAXN = 1e5 + 50;
    int vist[MAXN] = {0};
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> cnt (n,0);
        for(int i = 0;i < n;i++){
            cnt[favorite[i]]++;
        }
        vector<int> dp (n,0);
        queue<int> q;
        for(int i = 0;i < n;i++){
            if(cnt[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int now = q.front();
            q.pop();
            int nxt = favorite[now];
            cnt[nxt]--;
            dp[nxt] = max(dp[nxt],dp[now] + 1);
            if(cnt[nxt] == 0) q.push(nxt);
        }
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0;i < n;i++){
            if(!vist[i] && cnt[i] != 0){
                int now = i;
                int nxt = favorite[i];
                int tot = 2;
                vist[now] = true;
                vist[nxt] = true;
                if(favorite[nxt] == now){
                    ans1 += dp[now] + dp[nxt] + 2;
                }else{
                    while(favorite[nxt] != now){
                        tot++;
                        nxt = favorite[nxt];
                        vist[nxt] = true;
                    }
                }
                ans2 = max(ans2,tot);
            }
        }
        return max(ans1,ans2);
    }
};