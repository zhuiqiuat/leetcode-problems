#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool f(vector<int>& citations,int m){
        int n = citations.size();
        int cnt = 0;
        for(int i = n - 1;i >= 0;i--){
            if(citations[i] >= m){
                cnt++;
            }else{
                break;
            }
        }
        if(cnt >= m){
            return true;
        }else{
            return false;
        }
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 1;
        int r = n;
        int ans = 0;
        while(l <= r){
            int m = ((r - l) >> 1) + l;
            if(f(citations,m)){
                ans = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return ans;
    }
};