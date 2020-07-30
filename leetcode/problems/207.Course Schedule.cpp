class Solution {

private:
    vector<vector<int>> g;
    bool *used;
    
    // Cycle Detection for directed graph
    bool dfs(int s, unordered_map<int, bool>& path){

        used[s] = true;
        path[s] = true;
        for(auto u: g[s]){
            if(!used[u]){
                if(dfs(u, path)) return true;
            }
            else if(path[u]) return true;
        }
        path[s] = false;

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        g.resize(numCourses);
        used = new bool[numCourses];
        for(int i = 0; i < numCourses; i ++){
            used[i] = false;
        }

        for(auto& edge: prerequisites){
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
        }

        unordered_map<int, bool> path;

        for(int i = 0; i < numCourses; i ++){
            if(dfs(i, path)) return false;
        }
        
        return true;
    }
};