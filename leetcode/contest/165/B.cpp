class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ret = vector<int>();
        if(tomatoSlices == 0 && cheeseSlices == 0){
            ret.push_back(0), ret.push_back(0);
            return ret;
        }
        else if(tomatoSlices <= cheeseSlices) return ret;
        else if(cheeseSlices * 4 == tomatoSlices){
            ret.push_back(tomatoSlices / 4);
            ret.push_back(0);
        }
        else if(cheeseSlices * 2 == tomatoSlices){
            ret.push_back(0);
            ret.push_back(tomatoSlices / 2);
        }
        else{
            int a = 0;
            // bool ok = false;
            while(tomatoSlices > 0){
                tomatoSlices -= 4, cheeseSlices -= 1;
                a++;
                if(cheeseSlices * 2 == tomatoSlices){
                    ret.push_back(a);
                    ret.push_back(tomatoSlices / 2);
                    // ok = true;
                    break;
                }
            }
        }
        return ret;
    }
};