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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ret = head;
        while(head->next != nullptr){
            ListNode* insert = new ListNode(__gcd(head->val, head->next->val), head->next);
            head->next = insert; head = insert->next;
        }
        return ret;
    }
};