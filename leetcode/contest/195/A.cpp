
class Solution {
public:
    bool isPathCrossing(string path) {

        int x = 0, y = 0;
        map<pair<int, int>, bool> mp;
        mp[make_pair(0, 0)] = true;

        for(int i = 0; i < path.size(); i ++){
            if(path[i] == 'N') y ++;
            else if(path[i] == 'E') x ++;
            else if(path[i] == 'S') y --;
            else x --;
            if(mp[make_pair(x, y)]) return true;
            mp[make_pair(x, y)] = true;
        }
        return false;
    }
};