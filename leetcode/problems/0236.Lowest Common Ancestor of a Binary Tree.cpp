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
    // recursion
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

    // Non recursion
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> stack, sp, sq;
        TreeNode* cur = root;
        TreeNode* prior = nullptr;
        int cnt = 0;

        while((cur || !stack.empty()) && cnt < 2){
            if(cur){
                stack.push_back(cur);
                cur = cur->left;
            }
            else{
                cur = stack.back();
                if(cur->right && cur->right != prior){
                    cur = cur->right;
                }
                else{
                    if(cur == p){
                        sp = vector<TreeNode*>(stack.rbegin(), stack.rend());
                        cnt ++;
                    }
                    if(cur == q){
                        sq = vector<TreeNode*>(stack.rbegin(), stack.rend());
                        cnt ++;
                    }
                    stack.pop_back();
                    prior = cur;
                    cur = nullptr;
                }
            }
        }
        for(int i = 0; i < sp.size(); i ++){
            for(int j = 0; j < sq.size(); j ++){
                if(sp[i] == sq[j]) return sp[i];
            }
        }
        return nullptr;
    }
};