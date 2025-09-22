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
    int getSmallest(TreeNode* root){
        if(root->left) return getSmallest(root->left);
        return root->val;
    }
    int getLargest(TreeNode* root){
        if(root->right) return getLargest(root->right);
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val != key){
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
            return root;
        }
        // root -> val == key
        if(root->right){
            int smallest = getSmallest(root->right);
            root->val = smallest;
            root->right = deleteNode(root->right, smallest);
        }else if(root->left){
            int largest = getLargest(root->left);
            root->val = largest;
            root->left = deleteNode(root->left, largest);
        }else{
            return nullptr;
        }
        return root;
    }
};