class Solution {
public:
    int lengthOfLastWord(string s) {
        
        for(int i = s.size() - 1; i >= 0; i --){
            if(s[i] != ' ') break;
            s.pop_back();
        }
        
        int res = 0;
        for(auto c: s){
            if(c == ' ') res = 0;
            else res += 1;
        }
        return res;
    }
};