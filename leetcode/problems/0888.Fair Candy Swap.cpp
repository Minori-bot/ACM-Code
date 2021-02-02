class Solution {

private:
    int sum(vector<int> &v){
        int res = 0;
        for(auto e: v){
            res += e;
        }
        return res;
    }

public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int bob = sum(A);
        int ali = sum(B);
        vector<int> res;

        int k = abs(bob - ali) / 2;
        if(bob < ali){
            for(auto e: A){
                if(binary_search(B.begin(), B.end(), e + k)){
                    res.push_back(e);
                    res.push_back(e + k);
                    break;
                }
            }
        }
        else{
            for(auto e: B){
                if(binary_search(A.begin(), A.end(), e + k)){
                    res.push_back(e + k);
                    res.push_back(e);
                    break;
                }
            }
        }
        assert(!res.empty());

        return res;
    }
};