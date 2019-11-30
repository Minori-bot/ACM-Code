class Solution:
    def toHexspeak(self, num):
        num = hex(int(num))[2:]
        char_set = {'a', 'b', 'c', 'd', 'e', 'f'}
        
        ret = ''
        for c in num:
            if c != '0' and c != '1' and c not in char_set:
                ret = 'ERROR'
                break
            elif c == '0':
                ret += 'O'
            elif c == '1':
                ret += 'I'
            else:
                ret += c.upper()
        return ret