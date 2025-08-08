#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
      vector<vector<int>> graph (26,vector<int> ());
      int cnt[26] = {0};
      for(int i = 0;i < 26;i++){
        cnt[i] = -1;
      }
      int tot = 0;
      for(int i = 0;i < words.size();i++){
        bool ok = true;
        int j = 0;
        if(i + 1 < words.size()){
            for(j = 0;j < min(words[i].size(),words[i + 1].size());j++){
                if(cnt[words[i][j] - 'a'] == -1) cnt[words[i][j] - 'a'] = 0;
                if(words[i][j] != words[i + 1][j]){
                    cout << words[i][j] << "\n";
                    cout << words[i + 1][j] << "\n";
                    graph[words[i][j] - 'a'].push_back(words[i + 1][j] - 'a');
                    if(cnt[words[i + 1][j] - 'a'] == -1){
                        cnt[words[i + 1][j] - 'a'] = 1;
                    }else{
                        cnt[words[i + 1][j] - 'a']++;
                    }
                    ok = false;
                    break;
                }
            }
            int b = j;
            for(;b < words[i + 1].size();b++){
                if(cnt[words[i + 1][b] - 'a'] == -1) cnt[words[i + 1][b] - 'a'] = 0;
            }
            if(ok){
                if(words[i].size() > words[i + 1].size()) return "";
            }
        }
        int a = j;
        for(;a < words[i].size();a++){
            if(cnt[words[i][a] - 'a'] == -1) cnt[words[i][a] - 'a'] = 0;
        }
      }
      string ans = "";
      queue<int> q;
      for(int i = 0;i < 26;i++){
        if(cnt[i] != -1){
            tot++;
            if(cnt[i] == 0){
                q.push(i);
            }
        }
      }
      while(!q.empty()){
        int now = q.front();
        q.pop();
        ans.push_back(now + 'a');
        for(auto& i : graph[now]){
            cnt[i]--;
            if(cnt[i] == 0){
                q.push(i);
            }
        }
      }
      cout << ans << "\n";
      return ans.size() == tot ? ans : "";
    }
};