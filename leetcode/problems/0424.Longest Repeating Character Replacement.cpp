class Solution {
public:
    int characterReplacement(string s, int k) {

        int *record = new int[26];
        fill(record, record + 26, 0);
        int l = 0, r = 0;
        int prior = 0;
        int res = 0;

        while(r < s.size()){
            record[s[r] - 'A'] ++;
            prior = max(prior, record[s[r] - 'A']);
            if(prior + k < r - l + 1){
                record[s[l++] - 'A'] --;
            }
            res = max(res, r - l + 1);
            r ++;
        }

        return res;
    }
};