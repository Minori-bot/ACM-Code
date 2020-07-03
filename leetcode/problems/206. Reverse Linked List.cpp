class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    ListNode* reverseList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return head;

        ListNode* dummyHead = new ListNode();
        ListNode* p = head;
        ListNode* r = head;

        while(p != nullptr){
            r = p->next;
            p->next = dummyHead->next;
            dummyHead->next = p;
            p = r;
        }

        return dummyHead->next;
    }
};