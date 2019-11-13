class Solution:
    def reverse(self, x):
        isp = False
        string = str(x)

        if string[0] == "-":
            isp = True
            string = string.replace("-", "")

        ret_string = list(reversed(string))
        num = "".join(ret_string)

        if int(num) > pow(2, 31) - 1:
            ret = 0
        elif isp:
            ret = -1 * int(num)
        else:
            ret = int(num)

        return ret
