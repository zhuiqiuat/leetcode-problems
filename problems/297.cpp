#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string ans = "";
    
    void getAns(TreeNode* root){
        if(root == NULL){
            ans += "#,";
            return;
        }
        ans += to_string(root -> val) + ",";
        getAns(root -> left);
        getAns(root -> right);
    }

    vector<string> sp(string& s){
        // cout << "s = " << s << "\n";
        vector<string> re;
        int start = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == ','){
                re.push_back(s.substr(start,i - start));
                start = i + 1;
            }
        }
        // for(string& tmp : re){
        //     cout << "tmp = " << tmp << "\n";
        // }
        return re;
    }
    vector<string> rel;
    int cnt = 0;

    TreeNode* getn(int val){
        TreeNode* node = new TreeNode;
        node -> val = val;
        node -> left = node -> right = NULL;
        return node;
    }

    TreeNode* getNode(){
        if(rel[cnt] == "#"){
            cnt++;
            return NULL;
        }
        TreeNode* no = getn(stoi(rel[cnt++]));
        no -> left = getNode();
        no -> right = getNode();
        return no;
        // return NULL;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        getAns(root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        rel = sp(data);
        return getNode();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));