class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> map;
        for(auto c: s) map[c] ++;
        int res = 0;
        for(auto it = map.begin(); it != map.end(); it ++){
            if(it->second % 2 == 0) res += it->second;
        }
        int even = 0;
        for(auto it = map.begin(); it != map.end(); it ++){
            if(it->second & 1){
                int t = 0;
                for(auto itt = map.begin(); itt != map.end(); itt ++){
                    if((itt->second & 1) && itt->first != it->first) t += itt->second - 1;
                }
                even = max(even, t + it->second);
            }
        }

        return even + res;
    }
};