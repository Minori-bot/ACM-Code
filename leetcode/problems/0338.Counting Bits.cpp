class Solution {

private:

    int popcount(int num){
        int ret = 0;
        while(num){
            ret += (num & 1);
            num >>= 1;
        }

        return ret;
    }

public:
    vector<int> countBits(int num) {

        vector<int> ret;
        for(int i = 0; i <= num; i ++){
            ret.push_back(popcount(i));
        }

        return ret;
    }
};