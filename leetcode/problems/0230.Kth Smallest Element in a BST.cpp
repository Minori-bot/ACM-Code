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
    
    unordered_map<int, int> count;
    
    void dfs(TreeNode* node){
        
        if(node == nullptr) return;
        
        dfs(node->left);
        dfs(node->right);
        int leftChild = node->left ? count[node->left->val] : 0;
        int rightChild = node->right ? count[node->right->val] : 0;
        count[node->val] = leftChild + rightChild + 1;
    }
    
    TreeNode* kth(TreeNode* node, int k){
        
        if(node == nullptr) return nullptr;
        
        int leftChild = node->left ? count[node->left->val] : 0;
        if(leftChild + 1 == k){
            return node;
        }
        if(leftChild + 1 < k){
            return kth(node->right, k - leftChild - 1);
        }
        return kth(node->left, k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        
        dfs(root);
        
        auto node = kth(root, k);
        assert(node != nullptr);
        
        return node->val;
    }
};
