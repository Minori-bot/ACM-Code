class Solution {
public:
    int minFlips(string target) {

        int res = 0, index = -1;

        for(int i = 0; i < target.size(); i ++){
            if(target[i] == '1'){
                index = i;
                break;
            }
        }
        if(index != -1){
            res ++;
            for(int i = index + 1; i < target.size(); i ++){
                if(target[i] != target[i - 1]) res ++;
            }
        }
        return res;
    }
};