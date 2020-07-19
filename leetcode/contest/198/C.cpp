class Solution {

private:

    int checkStr(int index, const string& s, vector<int>& l, vector<int>& r){

        int right = r[s[index] - 'a'];

        for(int i = index; i < right; i ++){
            if(l[s[i] - 'a'] < index){
                return -1;
            }
            right = max(right, r[s[i] - 'a']);
        }
        return right;
    }

public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> l(26, INT_MAX);
        vector<int> r(26, INT_MIN);
        vector<string> res;

        for(int i = 0; i < s.size(); i ++){
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
        }

        int realRight = INT_MAX;
        string prior = "";
        for(int i = 0; i < s.size(); i ++){
            if(i > realRight){
                res.push_back(prior);
                realRight = INT_MAX;
                prior.clear();
            }
            if(l[s[i] - 'a'] == i){
                int right = checkStr(i, s, l, r);
                if(right != -1){
                    realRight = min(realRight, right);
                    prior = s.substr(i, realRight - i + 1);
                }
            }
        }
        if(!prior.empty()) res.push_back(prior);
        return res;
    }
};