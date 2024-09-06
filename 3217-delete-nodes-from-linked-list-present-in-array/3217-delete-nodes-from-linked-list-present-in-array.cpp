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
    bool inums[131072];
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<ListNode*> v;
        for(int i=0; i<nums.size(); i++) inums[nums[i]] = true;
        while(head != nullptr){
            if(!inums[head->val]) v.push_back(head);
            head = head->next;
        }
        for(int i=1; i<v.size(); i++){
            v[i-1]->next = v[i];
        }
        return v[0];
    }
};