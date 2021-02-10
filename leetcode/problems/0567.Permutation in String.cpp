class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int *record = new int[26];
        fill(record, record + 26, 0);
        for(auto c: s1) record[c - 'a'] ++;
        
        int l = 0, r = -1;
        while(r + 1 < (int)s2.size()){
            record[s2[++r] - 'a'] --;
            if(r - l + 1 == s1.size()){
                bool ok = true;
                for(int i = 0; i < 26; i ++){
                    if(record[i] != 0){
                        ok = false;
                    }
                }
                if(ok) return true;
                record[s2[l++] - 'a'] ++;
            }
        }
        return false;
    }
};