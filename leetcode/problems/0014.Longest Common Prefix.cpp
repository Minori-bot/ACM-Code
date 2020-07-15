// Praticing trie...
// Using the trie can be too solw..

class Trie {

private:

    struct Node{
        bool isWord;
        map<char, Node*> next;
        Node(){
            this->isWord = false;
        }
    };

    Node *root;
    int count;

public:

    Trie(){
        root = new Node();
        count = 0;
    }

    void insert(const string& word){

        Node* cur = root;
        for(int i = 0; i < word.size(); i ++){
            if(cur->next.find(word[i]) == cur->next.end()){
                cur->next.insert(make_pair(word[i], new Node()));
            }
            cur = cur->next[word[i]];
        }
        cur->isWord = true;
        count ++;
    }

    int solve(vector<string> &strs){

        int res = 0;
        Node* cur = root;

        while(cur->next.size() == 1){
            cur = cur->next.begin()->second;
            res ++;
        }
        return res;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        auto trie = Trie();
        int minLen = INT_MAX;
        for(auto& s: strs){
            trie.insert(s);
            minLen = min(minLen, (int)s.size());
        }
        
        return strs.front().substr(0, min(minLen, trie.solve(strs)));
    }
};


//    O(S) Solution 
//    string longestCommonPrefix(vector<string>& strs) {
//
//        string prefix = strs.front();
//
//        for(int i = 1; i < strs.size(); i ++){
//            while(strs[i].find(prefix) != 0){
//                prefix = prefix.substr(0, prefix.size() - 1);
//                if(prefix.empty()) return "";
//            }
//        }
//
//        return prefix;
//    }