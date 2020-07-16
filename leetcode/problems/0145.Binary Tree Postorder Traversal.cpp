class Solution {
public:

    // Non recursive
    // Using two stacks
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ret;
        if(root == nullptr) return ret;

        stack<TreeNode*> stack, output;

        stack.push(root);
        while(!stack.empty()){

            auto prior = stack.top();
            stack.pop();
            output.push(prior);

            if(prior->left != nullptr){
                stack.push(prior->left);
            }
            if(prior->right != nullptr){
                stack.push(prior->right);
            }
        }

        while(!output.empty()){
            ret.push_back(output.top()->val);
            output.pop();
        }

        return ret;
    }

    // Using a prior point
    vector<int> postorderTraversal2(TreeNode* root) {

        vector<int> ret;
        stack<TreeNode*> s;

        TreeNode* cur = root;
        TreeNode* prior = nullptr;
        while(cur || !s.empty()){

            if(cur){
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = s.top();
                if(cur->right && cur->right != prior){
                    cur = cur->right;
                    // s.push(cur);
                    // cur = cur->left;
                }
                else{
                    s.pop();
                    ret.push_back(cur->val);
                    prior = cur;
                    cur = nullptr;
                }
            }
        }

        return ret;
    }

};