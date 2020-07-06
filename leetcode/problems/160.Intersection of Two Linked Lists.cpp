class Solution {
    
private:
    
    int getSize(ListNode *head){
        int res = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            res ++;
            cur = cur->next;
        }
        return res;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int alen = getSize(headA), blen = getSize(headB);
        
        if(alen < blen){
            swap(alen, blen);
            swap(headA, headB);
        }
        
        int x = alen - blen;
        ListNode* cur = headA;
        for(int i = 0; i < x; i ++){
            cur = cur->next;
        }
        
        ListNode *curA = cur;
        ListNode *curB = headB;
        while(curA && curB && curA != curB){
            curA = curA->next;
            curB = curB->next;
        }
        
        return curA;
    }
};