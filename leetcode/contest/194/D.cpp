class UnionFind {

private:
    vector<int> f;
    int n;
public:
    UnionFind(int n) {
        f.resize(n);
        this->n = n;
        for(int i = 0; i < n; i ++) {
            f[i] = i;
        }
    }

    int find(int p) {
        while(p != f[p]) {
            f[p] = f[f[p]];
            p = f[p];
        }
        return p;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void merge(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot == qRoot) return;
        f[pRoot] = qRoot;
    }
};

class Solution {

private:
    map<pair<int, int>, bool> mp;

    int mst(int n, vector<vector<int>>& edges, vector<int> base = vector<int>()) {
        UnionFind uf = UnionFind(n);
        int ret = 0, cnt = 0;
        if(!base.empty()) {
            ret += base[2];
            cnt ++;
            uf.merge(base[0], base[1]);
        }

        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            bool tag = mp[make_pair(u, v)];
            if(!tag || uf.isConnected(u, v)) continue;
            uf.merge(u, v);
            ret += edge[2];
            if(++ cnt == n - 1) break;
        }
        return cnt == n - 1 ? ret : INT_MAX;
    }

public:
    vector<int> critical, pseudo;
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        for(int i = 0; i < edges.size(); i ++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        for(auto& edge: edges) {
            mp[make_pair(edge[0], edge[1])] = true;
        }
        int oriMst = mst(n, edges);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            mp[make_pair(u, v)] = false;
            int curMst = mst(n, edges);
            if(curMst > oriMst) {
                critical.push_back(edge[3]);
            }
            else {
                int cost = mst(n, edges, edge);
                if(cost == oriMst){
                    pseudo.push_back(edge[3]);
                }
            }
            mp[make_pair(u, v)] = true;
        }

        vector<vector<int>> res;
        sort(critical.begin(), critical.end());
        sort(pseudo.begin(), pseudo.end());
        res.push_back(critical);
        res.push_back(pseudo);
        return res;
    }
};