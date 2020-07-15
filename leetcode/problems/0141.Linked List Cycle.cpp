class Solution {


public:

    // two points
    // time complexity: O(n)
    // space complexity: O(1)
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }

//    hash table
//   time complexity: O(n)
//   space complexity: O(n)
//    bool hasCycle(ListNode *head) {
//
//        ListNode* slow = head;
//        ListNode* fast = head;
//
//        while(fast && fast->next){
//            fast = fast->next->next;
//            slow = slow->next;
//            if(slow == fast){
//                return true;
//            }
//        }
//        return false;
//    }
};