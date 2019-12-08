class Solution:
    def subtractProductAndSum(self, n):
        m = str(n)
        x, y = 1, 0
        for i in m:
            x *= int(i)
        y = sum([int(e) for e in m])
        return x - y
