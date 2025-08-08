#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> arr;

    int find(int n){
        while(arr[n] != n) n = arr[n];
        return n;
    }

    bool kno(int n){
        return find(n) == 0 ? true : false;
    }

    void uni(int a,int b){
        int fa = find(a);
        int fb = find(b);
        if(fb == 0){
            arr[fa] = 0;
        }else{
            arr[fb] = fa;
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        for(int i = 0;i < n;i++){
            arr.push_back(i);
        }
        arr[firstPerson] = 0;
        map<int,vector<vector<int>>> sta;
        for(auto& m : meetings){
            vector<int> tmp;
            tmp.push_back(m[0]);
            tmp.push_back(m[1]);
            sta[m[2]].push_back(tmp);
        }
        for(auto& [t,v] : sta){
            for(auto& ve : v){
                uni(ve[0],ve[1]);
            }
            for(auto& ve : v){
                if(!kno(ve[0])) arr[ve[0]] = ve[0];
                if(!kno(ve[1])) arr[ve[1]] = ve[1];
            }
        }
        vector<int> ans;
        for(int i = 0;i < arr.size();i++){
            if(kno(i)) ans.push_back(i);
        }
        return ans;
    }
};