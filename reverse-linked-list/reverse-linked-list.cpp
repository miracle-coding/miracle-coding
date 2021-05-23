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
    ListNode* reverseList(ListNode* head) {
        if (!head) return {};
        ListNode *tail = nullptr, *ptr = head, *rhead = head;
        while(rhead) {            
            ptr = rhead;
            rhead = rhead->next;
            ptr->next = tail;
            tail = ptr;
        }
        return ptr;
    }
};