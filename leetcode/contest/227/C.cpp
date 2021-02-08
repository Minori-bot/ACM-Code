class Solution {
public:
    string largestMerge(string word1, string word2) {
        
        string merge;
        int i = 0, j = 0;
        
        while(i < word1.size() && j < word2.size()){
            if(word1[i] < word2[j]){
                merge.push_back(word2[j++]);
            }
            else if(word1[i] > word2[j]){
                merge.push_back(word1[i++]);
            }
            else{
                string p = word1.substr(i, word1.size() - i);
                string q = word2.substr(j, word2.size() - j);
                if(p > q){
                    merge.push_back(word1[i++]);
                }
                else{
                    merge.push_back(word2[j++]);
                };
            }
        }
        if(i < word1.size()) merge += word1.substr(i, word1.size() - i);
        if(j < word2.size()) merge += word2.substr(j, word2.size() - j);
        
        return merge;
    }
};