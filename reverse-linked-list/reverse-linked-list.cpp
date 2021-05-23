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
    ListNode* _reverseList(ListNode* head, ListNode* prev=nullptr) {
        if (!head) return prev;
        ListNode* p = _reverseList(head->next, head);
        head->next = prev;
        return p;
    }
    ListNode* reverseList(ListNode* head) {
        // Recursive
        return _reverseList(head);
        
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