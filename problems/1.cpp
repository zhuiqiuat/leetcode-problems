#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int sum) {
        unordered_map<int,int> mp;
        for(int i = nums.size() - 1;i >= 0;i--){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
        }
        for(int i = 0;i < nums.size();i++){
            int tar = sum - nums[i];
            if(mp.find(tar) != mp.end() && mp[tar] != i){
                return {i,mp[tar]};
            }
        }
        return vector<int> ();
    }
};