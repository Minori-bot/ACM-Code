class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr) return nullptr;

        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead->next;

        while(cur->next != nullptr){
            if(cur->next->val == cur->val){
                ListNode* p = cur->next;
                cur->next = p->next;
                delete p;
            }
            else{
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};