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
    multiset<long long> sums;
    int helper(TreeNode* root, int targetSum, long long curSum) {
        if(!root) return 0;
        curSum += root->val;
        int ans = sums.count(curSum - targetSum);
        sums.insert(curSum);
        ans += helper(root->left, targetSum, curSum);
        ans += helper(root->right, targetSum, curSum);
        sums.erase(sums.lower_bound(curSum));
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        sums.insert(0);
        return helper(root, targetSum, 0);
    }
};