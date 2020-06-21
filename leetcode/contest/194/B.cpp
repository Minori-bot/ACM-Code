class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {

        map<string, int> mp;
        vector<string> ret;

        for(auto& name: names){
            if(!mp[name]){
                mp[name] ++;
                ret.push_back(name);
            }
            else{
                int val = mp[name];
                string cur(name);
                cur += "(" + to_string(val) + ")";
                while(mp[cur]){
                    val ++;
                    cur = name;
                    cur += "(" + to_string(val) + ")";
                }
                ret.push_back(cur);
                mp[name] ++;
                mp[cur] ++;
            }
        }
        return ret;
    }

};