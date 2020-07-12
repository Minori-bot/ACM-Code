class Solution {

private:
    static const int N = 30005;
    vector<pair<int, double>> g[N];

    void addEdge(int u, int v, double c){
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, c));
    }

    double bfs(int start, int end){

        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> pq;
        unordered_map<int, bool> mp;

        pq.push(make_pair(1.0, start));
        while(!pq.empty()){

            auto cur = pq.top();
            pq.pop();
            int u = cur.second;
            double d = cur.first;
            if(mp[u]) continue;
            mp[u] = true;

            if(u == end){
                return d;
            }

            for(auto &edge: g[u]){
                int v = edge.first;
                double x = edge.second;

                if(!mp[v]){
                    pq.push(make_pair(d * x, v));
                }
            }
        }
        return 0;
    }

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        for(int i = 0; i < edges.size(); i ++){
            int u = edges[i][0], v = edges[i][1];
            double c = succProb[i];

            addEdge(u, v, c);
        }

        return bfs(start, end);
    }
};
