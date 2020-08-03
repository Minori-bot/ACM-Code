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
    
    bool bfs(TreeNode* root, int sum){
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, root->val));
        
        while(!q.empty()){
            auto node = q.front().first;
            auto val = q.front().second;
            q.pop();
            
            if((!node->left && !node->right) && val == sum){
                return true;
            }
            if(node->left){
                q.push(make_pair(node->left, val + node->left->val));
            }
            if(node->right){
                q.push(make_pair(node->right, val + node->right->val));
            }
        }
        return false;
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
        if(root == nullptr) return false;
        
        return bfs(root, sum);
    }
};