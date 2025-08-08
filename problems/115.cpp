#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unsigned long long cnt[1050][1050] = {0};
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        for(int i = 0;i <= n;i++){
            cnt[i][0] = 1;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i - 1] == t[j - 1]){
                    cnt[i][j] = cnt[i - 1][j - 1];
                    cnt[i][j] += cnt[i - 1][j];
                }else{
                    cnt[i][j] = cnt[i - 1][j];
                }
            }
        }
        return (int) cnt[n][m];
    }
};