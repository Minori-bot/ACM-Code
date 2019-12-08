class Solution:
    def smallestDivisor(self, nums, threshold):
        l, r = 1, max(nums) + 1

        while l < r:
            mid = (l + r) // 2
            val = [int(math.ceil(e / mid)) for e in nums]
            if sum(val) <= threshold:
                r = mid
            else:
                l = mid + 1
        return l