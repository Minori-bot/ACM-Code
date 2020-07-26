class Solution {

private:

    vector<int> dfs(TreeNode* node, int dist, int& result){

        vector<int> counts(dist + 1, 0);

        if(node == nullptr) return counts;

        if(node->left == nullptr && node->right == nullptr){
            counts[1] = 1;
        }
        auto leftCounts = dfs(node->left, dist, result);
        auto rightCounts = dfs(node->right, dist, result);

        for(int i = 1; i < dist + 1; i ++){
            for(int j = 1; j < dist + 1; j ++){
                if(i + j <= dist) result += leftCounts[i] * rightCounts[j];
            }
        }
        for(int i = 1; i < dist + 1; i ++){
            counts[i] += leftCounts[i - 1] + rightCounts[i - 1];
        }
        return counts;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        
        int res = 0;
        dfs(root, distance, res);
        
        return res;
    }
};