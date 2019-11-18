class Solution {
    
public:
    int maxSumDivThree(vector<int>& nums) {

        int ret = 0;
        for(auto p: nums){
            if(p % 3 == 0) ret += p;
        }
        vector<int> m1, m2;
        int sum = 0;
        for(int p: nums){
            if(p % 3 == 1) m1.push_back(p), sum += p;
            if(p % 3 == 2) m2.push_back(p), sum += p;
        }
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());

        int val = 0x3f3f3f3f;
        if(sum % 3 == 1){
            if(!m1.empty()) val = m1[0];
            if(m2.size() > 1) val = min(val, m2[0] + m2[1]);
        }
        else if(sum % 3 == 2){
            if(!m2.empty()) val = m2[0];
            if(m1.size() > 1) val = min(val, m1[0] + m1[1]);
        }
        else{
            val = 0;
        }

        return ret + sum - val;
    }
};