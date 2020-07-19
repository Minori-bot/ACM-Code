class Solution {

static const int N = 200015;

private:
    vector<int> g[N];
    vector<vector<int>> numbers;
    bool used[N];

    void addEdge(int u, int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int s, const string& labels){
        used[s] = true;
        for(int i = 0; i < g[s].size(); i ++){
            int u = g[s][i];
            if(!used[u]){
                dfs(u, labels);
                for(int i = 0; i < 26; i ++){
                    numbers[s][i] += numbers[u][i];
                }
            }
        }
        numbers[s][labels[s] - 'a'] ++;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        for(auto& edge: edges){
            addEdge(edge[0], edge[1]);
        }
        numbers.resize(n);
        for(int i = 0; i < n; i ++){
            used[i] = false;
            numbers[i] = vector<int>(26, 0);
        }
        dfs(0, labels);
        vector<int> ret;
        for(int i = 0; i < n; i ++){
            ret.push_back(numbers[i][labels[i] - 'a']);
        }
        return ret;
    }
};