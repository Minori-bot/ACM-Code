class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        set<int> dry;
        map<int, int> full;
        vector<int> ret;

        for(int i = 0; i < rains.size(); i ++){
            if(rains[i] == 0){
                dry.insert(i);
                ret.push_back(1);
            }
            else{
                int lake = rains[i];
                if(full.find(lake) != full.end()){
                    // auto it = lower_bound(dry.begin(), dry.end(), full[lake]);
                    auto it = dry.upper_bound(full[lake]);
                    if(it == dry.end()){
                        ret.clear();
                        return ret;
                    }
                    ret[*it] = lake;
                    dry.erase(*it);
                }
                ret.push_back(-1);
                full[lake] = i;
            }
        }

        return ret;
    }
};