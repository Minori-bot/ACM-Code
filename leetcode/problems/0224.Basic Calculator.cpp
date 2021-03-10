class Solution {

private:

    inline int trans(string s){
        int ret = 0;
        for(auto c: s){
            ret = ret * 10 + (c - '0');
        }
        return ret;
    }
    
    void calc(stack<int>& dig, stack<int>& op, char c){
        while(!op.empty() && op.top() != '('){
            int b = dig.top(); dig.pop();
            int a = dig.top(); dig.pop();
            char cur = op.top(); op.pop();
            if(cur == '+') dig.push(a + b);
            if(cur == '-') dig.push(a - b);
        }
        if(c == ')') op.pop();
        else op.push(c);
    }

    int solve(string s){
        stack<int> dig, op;
        for(int i = 0; i < s.size();){
            if(isdigit(s[i])){
                string num;
                while(isdigit(s[i])) num += s[i++];
                dig.push(trans(num));
            }
            else{
                if(s[i] == '(') op.push(s[i]);
                else calc(dig, op, s[i]);
                i ++;
            }
        }
        assert(!dig.empty());
        
        return dig.top();
    }

public:
    int calculate(string s) {
    
        int p = -1;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '"'){
                p = i;
                break;
            }
        }
        string t = s.substr(p + 1, s.size() - p - 1);
        string exp = "(";
        for(auto c: t){
            if(c != ' '){
                if(c == '+') exp += c;
                else if(c == '-' && exp.back() == '('){
                    exp += '0', exp += c;
                }
                else exp += c;
            }
        }
        exp += ')';

        return solve(exp);
    }
};