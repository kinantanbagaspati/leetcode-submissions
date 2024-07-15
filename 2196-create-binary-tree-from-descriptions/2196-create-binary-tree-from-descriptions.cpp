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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        bool isPar[131072], isChild[131072];
        for(int i=0; i<131072; i++){
            isPar[i] = false; isChild[i] = false;
        }
        for(int i=0; i<descriptions.size(); i++){
            isPar[descriptions[i][0]] = true;
            isChild[descriptions[i][1]] = true;
        }
        TreeNode* nodes[131072];
        for(int i=0; i<131072; i++){
            if(isPar[i] || isChild[i]) nodes[i] = new TreeNode(i);
        }
        for(int i=0; i<descriptions.size(); i++){
            if(descriptions[i][2]){
                nodes[descriptions[i][0]]->left = nodes[descriptions[i][1]];
            }else{
                nodes[descriptions[i][0]]->right = nodes[descriptions[i][1]];
            }
        }
        for(int i=0; i<131072; i++){
            if(isPar[i] && !isChild[i]) return nodes[i];
        }
        return nullptr;
    }
};