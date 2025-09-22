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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        vector<pair<TreeNode*, int>> q;
        int qh = 0;
        q.push_back({root, 0});
        while(qh < q.size()){
            TreeNode* head = q[qh].first;
            if(head->left) q.push_back({head->left, q[qh].second + 1});
            if(head->right) q.push_back({head->right, q[qh].second + 1});
            if(ans.size() > q[qh].second){
                ans[q[qh].second] = head->val;
            }else{
                ans.push_back(head->val);
            }
            qh++;
        }
        return ans;
    }
};