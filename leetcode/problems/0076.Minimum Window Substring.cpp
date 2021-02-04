class Solution {
private:
    bool contains(int buffer[], int vis[]){
        for(int i = 0; i < 256; i ++){
            if(buffer[i] && buffer[i] > vis[i]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {

        int l = 0, r = -1;
        int res = s.size() + 1;
        int *vis = new int[256];
        int *buffer = new int[256];
        fill(vis, vis + 256, 0);
        fill(buffer, buffer + 256, 0);
        string ret;

        for(auto c: t) buffer[c] ++;

        while(l < s.size()){
            if(r + 1 < s.size() && !contains(buffer, vis)){
                vis[s[++r]] ++;
            }
            else{
                vis[s[l++]] --;
            }
            if(contains(buffer, vis) && r - l + 1 < res){
                res = r - l + 1;
                ret = s.substr(l, r - l + 1);
            }
        }

        return ret;
    }
};