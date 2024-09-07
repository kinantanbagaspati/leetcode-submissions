/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     char val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(char x) : val(x), next(nullptr) {}
 *     ListNode(char x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     char val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<char> list;
    char stck[3000];
    short sz = 0;
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(list.size() == 0){
            while(head != nullptr){
                list.push_back(head->val); head = head->next;
            }
        }
        stck[sz] = root->val; sz++;
        //for(char i=0; i<sz; i++) cout << stck[i] << ' ';
        //cout << endl;
        if(sz >= list.size()){
            bool bisa = true;
            for(char i=0; i<list.size(); i++) bisa = (list[list.size()-1-i] == stck[sz-1-i]) && bisa;
            if(bisa) return true;
        }
        if(root->left != nullptr && isSubPath(head, root->left)) return true;
        if(root->right != nullptr && isSubPath(head, root->right)) return true;
        sz--;
        return false;
    }
};