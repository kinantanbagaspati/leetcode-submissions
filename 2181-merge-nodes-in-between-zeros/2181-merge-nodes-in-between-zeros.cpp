/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(head->next == nullptr) return nullptr;
        ListNode* cur = head->next->next;
        while(cur->val != 0){
            head->next->val += cur->val;
            cur = cur->next;
        }
        head->next->next = mergeNodes(cur);
        return head->next;
    }
};