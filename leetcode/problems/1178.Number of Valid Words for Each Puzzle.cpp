class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {

        unordered_map<int, int> map;
        for(auto& word: words){
            int k = 0;
            for(auto c: word){
                k |= (1 << (c - 'a'));
            }
            if(__builtin_popcount(k) <= 7){
                map[k] ++;
            }
        }

        vector<int> ret;
        for(auto& puzzle: puzzles){
            int cnt = 0;
            for(int i = 0; i < (1 << 6); i ++){
                int k = 0;
                for(int j = 0; j < 6; j ++){
                    if(i & (1 << j)){
                        k |= (1 << (puzzle[j + 1] - 'a'));
                    }
                }
                k |= (1 << puzzle[0] - 'a');
                if(map.find(k) != map.end()){
                    cnt += map[k];
                }
            }
            ret.push_back(cnt);
        }

        return ret;
    }
};