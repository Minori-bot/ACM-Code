class Solution {
public:
    int xorOperation(int n, int start) {

        vector<int> v;
        for(int i = 0; i < n; i ++){
            v.push_back(start + i * 2);
        }
        int ret = 0;
        for(auto& e: v) ret ^= e;
        return ret;
    }
};