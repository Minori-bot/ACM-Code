class Solution {

private:

    string invert(string s){

        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        return s;
    }
public:
    char findKthBit(int n, int k) {

        string prior = "0";
        string cur;

        for(int i = 1; i <= n; i ++){
            string t = invert(prior);
            reverse(t.begin(), t.end());
            cur = prior;
            cur.append("1").append(t);
            // cout << prior << " " << cur << endl;
            prior = cur;
        }
        
        return cur[k - 1];
    }
};