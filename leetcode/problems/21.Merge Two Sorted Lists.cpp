class Solution {

private:

    void pushFront(ListNode* head, ListNode* p){
        p->next = head->next;
        head->next = p;
    }


public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* newList = new ListNode(0, nullptr);
        
        
        // 测试王道中头插法的正确性
        // 本题应使用尾插法一步到位
        while(p && q){

            if(p->val < q->val){
                ListNode* cur = p;
                p = p->next;
                pushFront(newList, cur);
            }
            else{
                ListNode* cur = q;
                q = q->next;
                pushFront(newList, cur);
            }
        }
        
        while(p){
            ListNode* cur = p;
            p = p->next;
            pushFront(newList, cur);
        }
        while(q){
            ListNode* cur = q;
            q = q->next;
            pushFront(newList, cur);
        }
        
        // 头插之后顺序是反的
        vector<int> res;
        ListNode* cur = newList->next;
        while(cur){
            res.push_back(cur->val);
            cur = cur->next;
        }
        reverse(res.begin(), res.end());
        newList->next = nullptr;
        cur = newList;
        for(auto e: res){
            cur->next = new ListNode(e, nullptr);
            cur = cur->next;
        }
        return newList->next;
    }
};