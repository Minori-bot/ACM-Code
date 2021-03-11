class Solution {

private:
    inline int trans(string num){
        int ret = 0;
        for(auto c: num){
            ret = ret * 10 + (c - '0');
        }
        return ret;
    }

    inline void calc(stack<int>& dig, stack<char>& op){
        char cur = op.top(); op.pop();
        int b = dig.top(); dig.pop();
        int a = dig.top(); dig.pop();
        if(cur == '*') dig.push(a * b);
        if(cur == '/') dig.push(a / b);
        if(cur == '+') dig.push(a + b);
        if(cur == '-') dig.push(a - b);
    }

    inline void calc(stack<int>& dig, stack<char>& op, char c){
        if(c == '*' || c == '/'){
            while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                calc(dig, op);
            }
            op.push(c);
        }
        else{
            while(!op.empty()){
                calc(dig, op);
            }
            op.push(c);
        }
    }

    int solve(string exp){
        stack<int> dig;
        stack<char> op;
        for(int i = 0; i < exp.size();){
            if(isdigit(exp[i])){
                string num;
                while(isdigit(exp[i])) num += exp[i++];
                dig.push(trans(num));
            }
            else{
                calc(dig, op, exp[i]);
                i ++;
            }
        }
        while(dig.size() > 1 && !op.empty()){
            calc(dig, op);
        }
        assert(dig.size() == 1);
        
        return dig.top();
    }

public:
    int calculate(string s) {

        string exp;
        for(auto c: s){
            if(c != ' ') exp += c;
        }
        return solve(exp);
    }
};