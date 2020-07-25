class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        digits.back() += 1;
        int t = digits.back() / 10;
        digits.back() %= 10;

        for(int i = digits.size() - 2; i >= 0; i --){
            if(t){
                digits[i] += 1;
                t = digits[i] / 10;
                digits[i] %= 10;
            }
            else break;
        }

        if(t){
            digits.push_back(0);
            for(int i = digits.size() - 1; i > 1; i --){
                digits[i] = digits[i - 1];
            }
            digits[0] = 1;
        }
        
        return digits;
    }
};