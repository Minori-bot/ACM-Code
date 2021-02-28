class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        
        bool a = false, b = false;
        for(int i = 1; i < A.size(); i ++){
            if(A[i] - A[i - 1] > 0) a = true;
            if(A[i] - A[i - 1] < 0) b = true;
            if(a && b) return false;
        }

        return true;
    }
};