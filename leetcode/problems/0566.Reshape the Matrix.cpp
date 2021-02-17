class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        int sum = 0;
        vector<int> v;
        for(int i = 0; i < nums.size(); i ++){
            for(int j = 0; j < nums[0].size(); j ++){
                v.push_back(nums[i][j]);
                sum ++;
            }
        }
        if(r * c != sum) return nums;

        auto ret = vector<vector<int>>(r, vector<int>(c, 0));
        int k = 0;
        for(int i = 0; i < r; i ++){
            for(int j = 0; j < c; j ++){
                ret[i][j] = v[k++];
            }
        }

        return ret;
    }
};