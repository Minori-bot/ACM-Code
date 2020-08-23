class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {

        vector<int> freq(n + 1, 0);

        for(int i = 0; i < rounds.size() - 1; i ++){
            if(rounds[i + 1] > rounds[i]){
                for(int j = rounds[i]; j < rounds[i + 1]; j ++){
                    freq[j] ++;
                }
            }
            else{
                for(int j = rounds[i]; j <= n; j ++){
                    freq[j] ++;
                }
                for(int j = 1; j < rounds[i + 1]; j ++){
                    freq[j] ++;
                }
            }
        }
        freq[rounds.back()] ++;
        vector<int> ret;
        int res = -1;
        for(int i = 1; i <= n; i ++) res = max(res, freq[i]);
        for(int i = 1; i <= n; i ++){
            if(freq[i] == res) ret.push_back(i);
        }

        return ret;
    }
};
