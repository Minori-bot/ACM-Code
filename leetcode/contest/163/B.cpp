class FindElements {

private:

    set<int> s;

public:
    FindElements(TreeNode* root) {

        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);

        while(!q.empty()){
            TreeNode *cur = q.front(); q.pop();
            if(cur->left != NULL){
                cur->left->val = 2 * cur->val + 1;
                s.insert(cur->left->val);
                q.push(cur->left);
            }
            if(cur->right != NULL){
                cur->right->val = 2 * cur->val + 2;
                s.insert(cur->right->val);
                q.push(cur->right);
            }
        }
    }

    bool find(int target) {
        return s.find(target) != s.end();
    }
};
