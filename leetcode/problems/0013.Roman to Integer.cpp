class Solution {

private:
    unordered_map<char, int> record;

    void buildMap(){
        record['I'] = 1;
        record['V'] = 5;
        record['X'] = 10;
        record['L'] = 50;
        record['C'] = 100;
        record['D'] = 500;
        record['M'] = 1000;
    }
public:
    int romanToInt(string s) {

        buildMap();

        int res = 0;
        for(int i = 0; i < s.size() - 1;){
            if(record[s[i]] >= record[s[i + 1]]){
                res += record[s[i]];
                i += 1;
            }
            else{
                int cur = record[s[i + 1]] - record[s[i]];
                res += cur;
                i += 2;
            }
        }
        
        if(s.size() == 1 || record[s[s.size() - 2]] >= record[s.back()]){
            res += record[s.back()];
        }

        return res;
    }
};