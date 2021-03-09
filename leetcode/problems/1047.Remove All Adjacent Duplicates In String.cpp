class Solution {
public:
    string removeDuplicates(string S) {

        stack<char> s;
        for(auto c: S){
            if(!s.empty() && c == s.top()){
                s.pop();
                continue;
            }
            else s.push(c);
        }
        string ret;
        while(!s.empty()){
            ret += s.top();
            s.pop();
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};