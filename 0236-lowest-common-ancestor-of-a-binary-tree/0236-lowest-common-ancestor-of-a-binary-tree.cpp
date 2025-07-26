/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void cari(TreeNode* root, TreeNode* r, vector<TreeNode*> &v){
        if(!root) return;
        v.push_back(root);
        if(v.size()>0 && v[v.size()-1] == r) return;
        cari(root->left, r, v);
        if(v.size()>0 && v[v.size()-1] == r) return;
        cari(root->right, r, v);
        if(v.size()>0 && v[v.size()-1] == r) return;
        v.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp, vq;  
        cari(root, p, vp); cari(root, q, vq);
        int idx = 0;
        while(idx < vp.size() && idx < vq.size() && vp[idx] == vq[idx]){
            //cout << vp[idx]->val << " " << vq[idx]->val << endl;
            idx++;
        };
        return vp[idx-1];  
    }
};