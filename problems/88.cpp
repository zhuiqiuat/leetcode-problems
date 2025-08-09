#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        vector<int> ans (n + m);
        int i = 0;
        int j = 0;
        int now = 0;
        while(i < n && j < m){
            ans[now++] = nums1[i] <= nums2[j] ? nums1[i++] : nums2[j++];
        }
        while(i < n){
            ans[now++] = nums1[i++];
        }
        while(j < m){
            ans[now++] = nums2[j++];
        }
        for(int i = 0;i < n + m;i++){
            nums1[i] = ans[i];
        }
    }
};