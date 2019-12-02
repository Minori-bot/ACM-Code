class Solution:
    def convert(self, s: str, numRows: int) -> str:
        col = ['' for _ in range(numRows)]

        if numRows == 1: return s
        cur = 0
        flg = False
        for char in s:
            col[cur] += char
            if cur == numRows - 1 or cur == 0:
                flg = not flg
            cur = cur + 1 if flg else cur - 1

        ret = ''.join([s for s in col])
        return ret