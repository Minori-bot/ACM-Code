class Solution {

private:

    //  Recursive
    // Calling by remove(head, val)
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    ListNode* remove(ListNode* cur, int val){

        if(cur == nullptr){
            return cur;
        }

        if(cur->val == val){
            ListNode *p = cur;
            cur = cur->next;
            delete p;
            return remove(cur, val);
        }
        cur->next = remove(cur->next, val);
        return cur;
    }


public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummyHead = new ListNode(0, head);
        ListNode* prior = dummyHead;
        ListNode* cur = head;

        while(cur != nullptr){
            if(cur->val == val){
                ListNode* del = cur;
                prior->next = cur->next;
                cur = cur->next;
                delete del;
            }
            else{
                cur = cur->next;
                prior = prior->next;
            }
        }

        return dummyHead->next;
    }
};