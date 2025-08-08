#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int f(vector<vector<int>>& matrix,long long m){
        int n = matrix.size();
        int cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] <= m){
                    cnt++;
                }else{
                    break;
                }
            }
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i = 0;i < n;i++){
            mn = min(mn,matrix[i][0]);
            mx = max(mx,matrix[i][n - 1]);
        }
        long long l = mn;
        long long r = mx;
        long long ans = 0;
        while(l <= r){
            long long m = l + ((r - l) >> 1);
            int cnt = f(matrix,m);
            if(cnt >= k){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};