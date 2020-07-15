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
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2){
        
        if(l2 > r2) return nullptr;
        
        TreeNode* node = new TreeNode(postorder[r1]);
        int p = l2;
        while(inorder[p] != postorder[r1]) p ++;
        node->left = buildTree(inorder, postorder, l1, l1 + p - l2 - 1, l2, p - 1);
        node->right = buildTree(inorder, postorder, l1 + p - l2, r1 - 1, p + 1, r2);
        
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        
        return buildTree(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};