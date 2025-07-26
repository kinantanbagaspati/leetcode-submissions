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
    int helper(TreeNode* root, int cur){
        if(!root) return 0;
        cur = max(cur, root->val);
        return helper(root->left, cur) + helper(root->right, cur) + (cur==root->val);
    }
    int goodNodes(TreeNode* root) {
        return helper(root, -1e9);
    }
};