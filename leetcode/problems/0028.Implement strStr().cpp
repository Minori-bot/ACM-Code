class Solution {

private:

    vector<int> getLPS(const string& pattern){

        // longest proper prefix which is also suffix
        // lps[0] is always 0
        vector<int> lps(pattern.size(), 0);

        // current index
        int i = 1;

        // length of the previous longest prefix suffix
        int len = 0;

        while(i < pattern.size()){
            if(pattern[i] == pattern[len]){
                lps[i ++] = ++ len;
            }
            else if(len){
                len = lps[len - 1];
            }
            else{
                lps[i ++] = 0;
            }
        }

        return lps;
    }

public:
    int strStr(string haystack, string needle) {

        if(haystack.empty()) return needle.empty() ? 0 : -1;
        if(needle.empty()) return 0;

        auto lps = getLPS(needle);

        int i = 0, j = 0;
        while(i < haystack.size() && j < needle.size()){
            if(haystack[i] == needle[j]){
                i ++, j ++;
                if(j == needle.size()){
                    return i - needle.size();
                }
            }
            else if(j){
                j = lps[j - 1];
            }
            else{
                i ++;
            }
        }

        return -1;
    }
};