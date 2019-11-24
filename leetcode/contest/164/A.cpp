class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        vector<pair<int, int>> v;
        for(int i = 0; i < points.size(); i ++){
            v.push_back(make_pair(points[i][0], points[i][1]));
        }
        int ret = 0;
        for(int i = 1; i < v.size(); i ++){
            int x = abs(v[i].first - v[i - 1].first);
            int y = abs(v[i].second - v[i - 1].second);
            int p = min(x, y);
            ret += p;
            if(x == p) ret += abs(y - p);
            else ret += abs(x - p);
        }
        return ret;
    }
};