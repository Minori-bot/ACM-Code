/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    pair<int, int> dfs(TreeNode* node){
        
        if(!node){
            return make_pair(0, 0);
        }

        auto left = dfs(node->left);
        auto right = dfs(node->right);
        int pf = max(left.first, left.second) + max(right.first, right.second);
        int ps = left.first + right.first + node->val;

        return make_pair(pf, ps);
    }
public:
    int rob(TreeNode* root) {
        
        auto res = dfs(root);

        return max(res.first, res.second);
    }
};