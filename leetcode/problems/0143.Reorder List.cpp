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
    
private:
    
    int getSize(ListNode* head){
        int res = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            res ++;
            cur = cur->next;
        }
        return res;
    }

public:
    void reorderList(ListNode* head) {
        
        if(head == nullptr) return;
        // if(head->next == nullptr) return;
        // if(head->next->next == nullptr) return;
        
        int len = getSize(head);
        int index = len / 2 + 1;
        
        ListNode* r = head;
        for(int i = 0; i < index - 1; i ++){
            r = r->next;
        }
        
        ListNode *p = nullptr;
        if(r != nullptr){
            p = r->next;
            r->next = nullptr;
        }
        
        ListNode* tempList = new ListNode(0, nullptr);
        while(p != nullptr){
            ListNode* t = p;
            p = p->next;
            t->next = tempList->next;
            tempList->next = t;
        }

        r = head;
        p = tempList->next;
        while(r->next != nullptr && p != nullptr){
            ListNode* t = p;
            p = p->next;
            t->next = r->next;
            r->next = t;
            r = r->next->next;
        }
    }
};