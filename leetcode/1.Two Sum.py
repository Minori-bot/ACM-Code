class Solution:
    def twoSum(self, nums, target):

        nums_dict = {nums[i]: i for i in range(len(nums))}

        for i in range(len(nums)):
            other = target - nums[i]
            if other in nums_dict and i != nums_dict[other]:
                return (i, nums_dict[other])

        raise ValueError("no soluion!")
