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
    
    int maximum(TreeNode* node){
        
        if(node->right == nullptr) return node->val;
        
        return maximum(node->right);
    }
    
    int minimum(TreeNode* node){
        
        if(node->left == nullptr) return node->val;
        
        return minimum(node->left);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        if(root == nullptr) return true;
        
        if(root->left){
            int p = maximum(root->left);
            if(p >= root->val) return false;
        }
        if(root->right){
            int p = minimum(root->right);
            if(p <= root->val) return false;
        }
        
        return isValidBST(root->left) && isValidBST(root->right);
    }
};