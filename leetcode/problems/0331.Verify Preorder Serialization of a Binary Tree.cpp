class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        if(preorder == "#") return true;
        if(preorder == "") return false;

        vector<string> s;
        string cur;
        for(auto c: preorder){
            if(c != ',') cur += c;
            else{
                s.push_back(cur);
                cur.clear();
            }
        }
        if(!cur.empty()) s.push_back(cur);
        while(1){
            vector<string> newOrder;
            bool ok = false;
            for(int i = 0; i < s.size();){
                if(i + 1 < s.size() && i + 2 < s.size() && s[i] != "#" && s[i + 1] == "#" && s[i + 2] == "#"){
                    newOrder.push_back("#");
                    i += 3;
                    ok = true;
                }
                else{
                    newOrder.push_back(s[i++]);
                }
            }
            if(!ok) return false;
            if(newOrder.size() == 1 && newOrder[0] == "#"){
                return true;
            }
            s = newOrder;
        }
    }
};