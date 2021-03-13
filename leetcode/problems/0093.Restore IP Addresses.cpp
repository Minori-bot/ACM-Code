class Solution {

private:
    vector<string> res;
    int trans(string s){
        int ret = 0;
        for(auto c: s){
            ret = ret * 10 + (c - '0');
        }
        return ret;
    }
    void dfs(const string& s, int index, int cnt, string cur){
        if(index >= s.size()) return;
        if(cnt == 3){
            int len = s.size() - index;
            if((len <= 3 && s[index] != '0') || len == 1){
                auto buffer = s.substr(index, len);
                int val = trans(buffer);
                if(val <= 255) res.push_back(cur + buffer);
            }
            return;
        }

        if(s[index] == '0'){
            dfs(s, index + 1, cnt + 1, cur + "0.");
        }
        else{
            for(int i = index; i < s.size() - 1; i ++){
                auto buffer = s.substr(index, i - index + 1);
                int val = trans(buffer);
                if(val > 255) break;
                dfs(s, i + 1, cnt + 1, cur + buffer + ".");
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        
        if(s.size() > 12){
            return res;
        }
        dfs(s, 0, 0, "");

        return res;
    }
};