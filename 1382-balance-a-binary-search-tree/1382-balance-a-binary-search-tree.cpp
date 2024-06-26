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
    int getDepth(TreeNode* root) {
        int res = 0;
        if(root->left != nullptr) res = max(1 + getDepth(root->left), res);
        if(root->right != nullptr) res = max(1 + getDepth(root->right), res);
        return res;
    }
    vector<int> vals;
    void traverse(TreeNode* root) {
        if(root->left != nullptr) traverse(root->left);
        vals.push_back(root->val);
        if(root->right != nullptr) traverse(root->right);
    }
    TreeNode* build(int lo, int hi) {
        int mid = (lo+hi)/2;
        TreeNode* ret = new TreeNode(vals[mid]);
        if(lo < mid) ret->left = build(lo, mid);
        if(mid+1 < hi) ret->right = build(mid+1, hi);
        return ret;
    }
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        return build(0, vals.size());
    }
};