#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const static int N = 1e5 + 50;

    int st[N];
    int r;

    int largestRectangleArea(vector<int>& heights) {
        r = 0;
        int n = heights.size();
        vector<pair<int,int>> v (n);
        int ans = -1;
        for(int i = 0;i < n;i++){
            while(r > 0 && heights[st[r - 1]] >= heights[i]){
                int ind = st[--r];
                v[ind].first = r > 0 ? st[r - 1] : -1;
                v[ind].second = i;
            }
            st[r++] = i;
        }
        while(r > 0){
            int ind = st[--r];
            v[ind].first = r > 0 ? st[r - 1] : -1;
            v[ind].second = n;
        }
        for(int i = n - 2;i >= 0;i--){
            if(v[i].second != n && heights[i] == heights[v[i].second]){
                v[i].second = v[v[i].second].second;
            }
        }
        for(int i = 0;i < n;i++){
            int l = v[i].first;
            int r = v[i].second;
            ans = max(ans,(r - l - 1) * heights[i]);
        }
        return ans;
    }
};