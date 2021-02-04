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


// cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0, r = -1, n = s.size();
        int res = 0;
        unordered_map<char, bool> vis;

        while(r + 1 < n){
            if(vis[s[r + 1] - 'a']){
                while(l < n && s[l] != s[r + 1]){
                    vis[s[l++] - 'a'] = false;
                }
                vis[s[l++] - 'a'] = false;
            }
            r ++;
            vis[s[r] - 'a'] = true;
            res = max(res, r - l + 1);
        }
    
        return res;
    }
};