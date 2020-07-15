class Solution:

    def median(self, a, b):
        n, m = len(a), len(b)
        if n > m:
            a, b, n, m = b, a, m, n

        imin, imax, half_arr = 0, n, (n + m + 1) // 2
        # [0...half_arr - 1] is the left part
        while imin <= imax:
            i = (imin + imax) // 2
            j = half_arr - i

            if i < n and a[i] < b[j - 1]:
                imin = i + 1
            elif i > 0 and a[i - 1] > b[j]:
                imax = i - 1
            else:
                # find a[i - 1], a[i]
                #      b[j - 1], b[j]
                if i == 0: max_left = b[j - 1]
                elif j == 0: max_left = a[i - 1]
                else: max_left = max(a[i - 1], b[j - 1])

                if (m + n) % 2 == 1:
                    return max_left

                if i == n: min_right = b[j]
                elif j == m: min_right = a[i]
                else: min_right = min(a[i], b[j])
                return (max_left + min_right) / 2

    def findMedianSortedArrays(self, nums1, nums2):
        return self.median(nums1, nums2)