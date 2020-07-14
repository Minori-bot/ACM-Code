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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == nullptr) return root;
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        
        auto leftChild = lowestCommonAncestor(root->left, p, q);
        auto rightChild = lowestCommonAncestor(root->right, p, q);
        
        if(leftChild && rightChild){
            return root;
        }
        else if(leftChild){
            return leftChild;
        }
        else{
            return rightChild;
        }
    }
};