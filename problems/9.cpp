#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i,j;
        for(i = 0,j = s.size() - 1;i <= j;i++,j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
};