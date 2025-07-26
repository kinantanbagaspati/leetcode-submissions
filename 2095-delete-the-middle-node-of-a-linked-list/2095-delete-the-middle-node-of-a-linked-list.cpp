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
    int getSz(ListNode* head){
        if(!(head->next)) return 1;
        return 1 + getSz(head->next);
    }
    ListNode* deleteMiddle(ListNode* head) {
        int sz = getSz(head);
        if(sz == 1) return nullptr;
        ListNode* cur = head;
        for(int i=1; i<=sz/2-1; i++){
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};