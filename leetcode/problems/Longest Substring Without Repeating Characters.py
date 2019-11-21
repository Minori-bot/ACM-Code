class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_dic = {}
        left = 0
        ret = 1 if s else 0
        for i in range(len(s)):
            if s[i] not in char_dic.keys() or char_dic[s[i]] < left:
                char_dic[s[i]] = i
                ret = max(ret, i - left + 1)
            else:
                index = char_dic[s[i]]
                ret = max(ret, i - left)
                left = index + 1
                char_dic[s[i]] = i
        return ret