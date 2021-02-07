class Solution {
public:
    int minimumLength(string s) {
        
        int l = 0, r = s.size() - 1;
        int res = s.size();
        
        while(l < r){
            if(s[l] != s[r]) break;
            char com = s[l];
            while(l < r && s[l] == com) l ++, res --;
            if(l == r){
                res = 0;
                break;
            }
            while(l < r && s[r] == com) r --, res --;
        }
        return res;
    }
};