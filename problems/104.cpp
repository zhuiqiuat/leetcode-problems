#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxdep(TreeNode* tree,int dep){
        int ma = -1;
        if(tree -> left){
            ma = max(maxdep(tree -> left,dep + 1),ma);
        }
        
        if(tree -> right){
            ma = max(maxdep(tree -> right,dep + 1),ma);
        }
        return ma == -1 ? dep : ma; 
    }

    int maxDepth(TreeNode* root) {
        if(root)
            return maxdep(root,1);
        else
            return 0;
    }
};