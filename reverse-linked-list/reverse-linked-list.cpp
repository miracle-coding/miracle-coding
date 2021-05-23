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
        // Recursive
        if (!head || !head->next) return head;
        ListNode* ptr = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ptr;
        
        // Iterative
        /*
        ListNode *prev = nullptr, *ptr = head, *rhead = head;
        while(rhead) {            
            ptr = rhead;
            rhead = rhead->next;
            ptr->next = prev;
            prev = ptr;
        }
        return ptr;
        */
    }
};