class Solution:

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:

        ret = ListNode(0)
        head = ret
        cur_l1 = l1
        cur_l2 = l2
        ok = False
        while cur_l1 and cur_l2:
            value = cur_l1.val + cur_l2.val + 1 if ok else cur_l1.val + cur_l2.val
            ok = False
            if value // 10:
                ok = True
                value %= 10
            ret.next = ListNode(value)
            ret = ret.next
            cur_l1 = cur_l1.next
            cur_l2 = cur_l2.next

        if cur_l1:
            while cur_l1:
                value = cur_l1.val + 1 if ok else cur_l1.val
                ok = False
                if value // 10:
                    ok = True
                    value %= 10
                ret.next = ListNode(value)
                ret = ret.next
                cur_l1 = cur_l1.next
        if cur_l2:
            while cur_l2:
                value = cur_l2.val + 1 if ok else cur_l2.val
                ok = False
                if value // 10:
                    ok = True
                    value %= 10
                ret.next = ListNode(value)
                ret = ret.next
                cur_l2 = cur_l2.next

        if ok:
            ret.next = ListNode(1)

        return head.next