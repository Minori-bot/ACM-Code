struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {

private:

    struct Node{
        int val;
        Node* left;
        Node* right;
        bool ltag, rtag;
        Node(): val(0), left(nullptr), right(nullptr), ltag(0), rtag(0){}
        Node(int x): val(x), left(nullptr), right(nullptr), ltag(0), rtag(0){}
        Node(int x, Node* left, Node* right): val(x), left(left), right(right), ltag(0), rtag(0){}
    };

    Node *root;

    Node* dfs(TreeNode* p){

        if(p == nullptr) return nullptr;

        Node* node = new Node(p->val);
        node->left = dfs(p->left);
        node->right = dfs(p->right);

        return node;
    }

    void visit(Node* p, Node*& prior){

        if(p->left == nullptr){
            p->left = prior;
            p->ltag = true;
        }
        if(prior != nullptr && prior->right == nullptr){
            prior->right = p;
            prior->rtag = true;
        }

        prior = p;
    }

    void buildThreadTree(Node* cur, Node*& prior){

        if(cur == nullptr) return;

        buildThreadTree(cur->left, prior);
        visit(cur, prior);
        buildThreadTree(cur->right, prior);

    }

    Node* find(Node* p){

        while(p && !p->ltag) p = p->left;
        return p;
    }

    Node* nextNode(Node* p){

        return p->rtag ? p->right : find(p->right);
    }

public:
    
    // Using InOrder Thread Tree
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ret;
        if(root == nullptr) return ret;

        this->root = dfs(root);

        Node* pre = nullptr;
        buildThreadTree(this->root, pre);

        for(auto p = find(this->root); p != nullptr; p = nextNode(p)){
            ret.push_back(p->val);
        }

        return ret;
    }
};