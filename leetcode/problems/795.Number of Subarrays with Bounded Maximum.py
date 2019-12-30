class Solution:

    def _count_sub(self, A, value):
        cur, ret = 0, 0
        while cur < len(A):
            while cur < len(A) and A[cur] > value:
                cur += 1
            if cur != len(A):
                size = 0
                while cur < len(A) and A[cur] <= value:
                    size += 1
                    cur += 1
                ret += size * (size - 1) // 2 + size
        return ret

    def numSubarrayBoundedMax(self, A, L, R):
        return self._count_sub(A, R) - self._count_sub(A, L - 1)
