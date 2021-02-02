class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();
        vector<int> res;

        for(int i = 0; i < n; i ++){
            int val = target - numbers[i];
            auto p = lower_bound(numbers.begin() + i + 1, numbers.end(), val);
            if(p != numbers.end()){
                int index = p - numbers.begin();
                if(numbers[index] == val){
                    res.push_back(i + 1);
                    res.push_back(index + 1);
                }
            }
        }
        assert(!res.empty());

        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int l = 0, r = numbers.size() - 1;

        while(l < r){
            if(numbers[l] + numbers[r] == target){
                int res[2] = {l + 1, r + 1};
                return vector<int>(res, res + 2);
            }
            else if(numbers[l] + numbers[r] < target){
                l ++;
            }
            else{
                r -- ;
            }
        }
        
        throw invalid_argument("No Solution.");
    }
};