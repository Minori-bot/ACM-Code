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
    
    int getHeight(TreeNode* node){
        if(node == nullptr) return 0;
        
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        
        if(root == nullptr) return true;
        
        int leftChild = getHeight(root->left);
        int rightChild = getHeight(root->right);
        if(abs(leftChild - rightChild) > 1) return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};