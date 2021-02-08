class Solution {
public:
    bool check(vector<int>& nums) {
        
        map<int, int> map;
        vector<int> v;
        for(auto e: nums){
            if(!map[e]){
                map[e] ++;
                v.push_back(e);
            }
        }
        
        // sort(nums.begin(), nums.end());
        // nums.erase(unique(nums.begin(), nums.end()), nums.end());
        vector<int> raw(v.begin(), v.end());
        sort(raw.begin(), raw.end());
        //cout << nums.size() << " " << raw.size() << endl;

        int j = 0;
        while(raw[j] != v[0]) j ++;

        int i = 0;
        while(i < v.size()){
            if(v[i] == raw[j]) i ++, j = (j + 1) % (int)v.size();
            else return false;
        }

        return true;
    }
};