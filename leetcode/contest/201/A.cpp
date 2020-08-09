class Solution {
public:
    string makeGood(string s) {

        while(true){
            bool good = true;
            for(int i = 1; i < s.size(); i ++){
                if(abs(s[i] - s[i - 1]) == 32){
                    good = false;
                    s = s.erase(i - 1, 2);
                    continue;
                }
            }
            if(good) break;
        }

        return s;
    }
};