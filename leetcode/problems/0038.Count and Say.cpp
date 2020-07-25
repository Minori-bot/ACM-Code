class Solution {
public:
    string countAndSay(int n) {

        string res, cur;

        cur = "1", res = "1";

        for(int i = 1; i < n; i ++){
            
            res.clear();
            vector<int> count(cur.size(), 0);
            count[0] = 1;

            for(int j = 1; j < cur.size(); j ++){
                if(cur[j] == cur[j - 1]){
                    count[j] = count[j - 1] + 1;
                    count[j - 1] = 0;
                }
                else count[j] = 1;
            }
            for(int j = 0; j < count.size(); j ++){
                if(count[j]){
                    res += to_string(count[j]);
                    res += cur[j];
                }
            }
            cur = res;
        }

        return cur;
    }
};