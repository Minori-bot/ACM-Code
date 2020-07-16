class Solution {
public:
    // Non recursive
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ret;
        stack<TreeNode*> s;
        
        TreeNode* cur = root;
        while(cur || !s.empty()){
            
            if(cur){
                ret.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
        
        return ret;
    }
};