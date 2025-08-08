#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<ll> arr;
    int help[50050];
    int merge(int start,int mid,int end){
        int ans = 0;
        int sum = 0;
        int j = mid + 1;
        for(int i = start;i <= mid;i++){
            while(j <= end && arr[i] > 2 * arr[j]){
                sum++;
                j++;
            }
            ans += sum;
        }
        int a = start;
        int b = mid + 1;
        int now = start;
        while(a <= mid && b <= end){
            help[now++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
        }
        while(a <= mid){
            help[now++] = arr[a++];
        }
        while(b <= end){
            help[now++] = arr[b++];
        }
        while(start <= end){
            arr[start++] = help[start];
        }
        return ans;
    }
    int solve(int start,int end){
        if(start == end) return 0;
        int mid = (start + end) / 2;
        return solve(start,mid) + solve(mid + 1,end) + merge(start,mid,end);
    }
    int reversePairs(vector<int>& tmp) {
        arr = vector<ll>(tmp.begin(),tmp.end());
        int ans = solve(0,tmp.size() - 1);
        return ans;
    }
};