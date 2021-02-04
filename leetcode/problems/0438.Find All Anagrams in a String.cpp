class Solution {
private:
    bool isAnagrams(int pc[], int vis[]){
        for(int i = 0; i < 26; i ++){
            if(vis[i] != pc[i]) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {

        int l = 0, r = -1;
        vector<int> ret;
        int *vis = new int[26];
        int *pc = new int[26];
        fill(vis, vis + 26, 0);
        fill(pc, pc + 26, 0);
        for(auto c: p){
            pc[c - 'a'] ++;
        }

        while(r + 1 < s.size()){
            vis[s[++r] - 'a'] ++;
            if(r - l + 1 == p.size()){
                if(isAnagrams(pc, vis)){
                    ret.push_back(l);
                }
                vis[s[l++] - 'a'] --;
            }
        }
        
        return ret;
    }
};