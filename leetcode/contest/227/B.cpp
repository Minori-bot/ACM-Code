class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());
        
        int res = 0;
        while(v[0] > 0 && v[1] > 0 && v[0] + v[1] > v[2]){
            v[0] --, v[1] --, res ++;
        }
        res += v[1];
        v[2] -= v[1];
        v[1] = 0;
        res += v[0];
        
        return res;
    }
};