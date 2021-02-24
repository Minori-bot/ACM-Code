class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        for(auto& p: A){
            reverse(p.begin(), p.end());
            for(auto& e: p){
                e ^= 1;
            }
        }

        return A;
    }
};