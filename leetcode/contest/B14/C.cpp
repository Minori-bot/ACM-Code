class Solution {

private:
    vector<int> g[10005];
    int size = 0;
    bool vis[10005];
    int sum[10005];

    void dfs(int s, vector<int> &parent, vector<int> &value){
        sum[s] = value[s];
        for(auto x: g[s]){
            dfs(x, parent, value);
            sum[s] += sum[x];
        }
        if(sum[s] == 0){
            vis[s] = true;
        }
    }

    void dfs(int s){
        size ++;
        for(auto x: g[s]){
            if(!vis[x]) dfs(x);
        }
    }

public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {

        int root = 0;
        for(int i = 0; i < nodes; i ++){
            if(parent[i] != -1){
                g[parent[i]].push_back(i);
            }
            else root = i;
        }
        dfs(root, parent, value);
        dfs(root);
        return size;
    }
};