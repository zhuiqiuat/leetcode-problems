#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                tmp.push(s[i]);
            }
            if(tmp.size() == 0){
                return false;
            }
            if(s[i] == ')'){
                if(tmp.top() != '('){
                    return false;
                }
                tmp.pop();
                continue;
            }
            if(s[i] == '}'){
                if(tmp.top() != '{'){
                    return false;
                }
                tmp.pop();
                continue;
            }
            if(s[i] == ']'){
                if(tmp.top() != '['){
                    return false;
                }
                tmp.pop();
                continue;
            }
        }
        if(tmp.size() != 0){
            return false;
        }else{
            return true;
        }
    }
};