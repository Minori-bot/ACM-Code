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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left == right) return head;
        
        auto dummyHead = new ListNode(0, head);
        auto cur = dummyHead, p = head, q = head;
        int t = 0;
        while(cur){
            if(t == left - 1) p = cur;
            if(t == right) q = cur->next;
            cur = cur->next;
            t ++;
        }
        cur = p->next;
        auto r = cur, last = cur;
        while(cur && cur != q){
            r = cur->next;
            cur->next = p->next;
            p->next = cur;
            cur = r;
        }
        last->next = q;

        return dummyHead->next;
    }
};