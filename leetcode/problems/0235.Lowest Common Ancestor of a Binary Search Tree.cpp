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
    TreeNode* LCA(TreeNode* root, TreeNode* p,  TreeNode* q){
        assert(root != nullptr);
        if(p->val < root->val && q->val < root->val){
            return LCA(root->left, p, q);
        }
        if(p->val > root->val && q->val > root->val){
            return LCA(root->right, p, q);
        }
        
        return root;
    }    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == nullptr) return nullptr;
        
        return LCA(root, p, q);
    }
};