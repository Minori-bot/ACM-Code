#include <bits/stdc++.h>
using namespace std;
using LL = long long;


class Solution {

private:

    int calc(const string &token){

        int res = 0;

        for(int i = token[0] == '-' ? 1 : 0; i < token.size(); i ++){
            res = res * 10 + (token[i] - '0');
        }

        return token[0] == '-' ? -res: res;
    }

    int calc(int a, int b, char _operator){

        if(_operator == '+'){
            return a + b;
        }
        else if(_operator == '-'){
            return a - b;
        }
        else if(_operator == '*'){
            return a * b;
        }
        else{
            return a / b;
        }
    }

public:
    int evalRPN(vector<string>& tokens) {

        stack<int> numbers;

        for(auto &c: tokens){
            if((isnumber(c[0])) || (c[0] == '-' && c.size() > 1)){
                int cur = calc(c);
                numbers.push(cur);
            }
            else{
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();

                numbers.push(calc(a, b, c[0]));
            }
        }

        return numbers.top();
    }
};

int main(){

    auto sol = Solution();

    vector<string> v = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout << sol.evalRPN(v) << endl;

    return 0;
}

