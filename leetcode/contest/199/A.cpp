class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        map<int, char> map;
        for(int i = 0; i < indices.size(); i ++){
            map.insert(make_pair(indices[i], s[i]));
        }
        string res;
        for(auto iter = map.begin(); iter != map.end(); iter ++){
            res.push_back(iter->second);
        }
        return res;
    }
};