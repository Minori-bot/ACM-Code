class Solution {
public:
    bool isValid(string s) {

        stack<int> record;

        for(auto &c: s){

            if(c == '(' || c == '[' || c == '{'){
                record.push(c);
            }
            else{
                if(record.empty()) return false;
                
                auto cur = record.top();
                record.pop();

                if(c == ')' && cur != '('){
                    return false;
                }
                else if(c == ']' && cur != '['){
                    return false;
                }
                else if(c == '}' && cur != '{'){
                    return false;
                }
            }
        }
        return record.empty();
    }
};