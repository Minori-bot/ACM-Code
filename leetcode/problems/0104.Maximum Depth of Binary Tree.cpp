/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    
    // Non recursion
    // Using levelorder by queue
    int bfs(TreeNode* root){
        
        queue<pair<TreeNode*, int>> queue;
        int res = 0;
        
        queue.emplace(root, 1);
        
        while(!queue.empty()){
            auto prior = queue.front();
            queue.pop();
            
            if(prior.first->left != nullptr){
                queue.emplace(prior.first->left, prior.second + 1);
            }
            if(prior.first->right != nullptr){
                queue.emplace(prior.first->right, prior.second + 1);
            }
            if(prior.first->left == nullptr && prior.first->right == nullptr){
                res = max(res, prior.second);
            }
        }
        return res;
    }
    
    // recurion
    int dfs(TreeNode* root){
        
        if(root == nullptr) return 0;
        
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
    
public:
    int maxDepth(TreeNode* root) {
        
        // return dfs(root);
        if(root == nullptr) return 0;
        
        return bfs(root);
    }
};