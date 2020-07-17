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

    bool bfs(TreeNode* root){

        queue<TreeNode*> queue;
        bool ok = false;

        queue.push(root);

        while(!queue.empty()){

            auto node = queue.front();
            queue.pop();
            
            if(ok && (node->left || node->right)){
                return false;
            }
            if(node->right && !node->left){
                return false;
            }
            if((node->left && !node->right) || (!node->left && !node->right)){
                ok = true;
            }
            
            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }
        
        return true;
    }

public:
    bool isCompleteTree(TreeNode* root) {
        
        return bfs(root);
    }
};
