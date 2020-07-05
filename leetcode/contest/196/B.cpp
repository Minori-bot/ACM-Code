class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        vector<int> record;

        for(auto e: right){
            record.push_back(n - e);
        }
        for(auto e: left){
            record.push_back(e);
        }

        return *max_element(record.begin(), record.end());
    }
};