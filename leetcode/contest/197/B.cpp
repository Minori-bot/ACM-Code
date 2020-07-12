class Solution {
    
    
    using LL = long long;

private:

    static const int p = (long long)1e9 + 7;

public:
    int numSub(string s) {

        int n = (int)s.size();
        vector<LL> record(n, 0);
        record[0] = s[0] == '1';
        LL res = record[0];

        for(int i = 1; i < s.size(); i ++){

            if(s[i] == '1'){
                record[i] = ((record[i - 1]) % p + 1) % p;
                res = (res % p + record[i] % p) % p;
            }
        }

        return (int)res;
    }
};