class Solution {

private:
    vector<string> res;
    const string record[10] = {"", "", "abc", "def",
                                "ghi", "jkl", "mno",
                                "pqrs", "tuv", "wxyz"};

    void dfs(const string& digits, int index, string& s){
        if(index == digits.size()){
            res.push_back(s);
            return;
        }

        for(auto c: record[digits[index] - '0']){
            s += c;
            dfs(digits, index + 1, s);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return res;
        
        string s = "";
        dfs(digits, 0, s);

        return res;
    }
};