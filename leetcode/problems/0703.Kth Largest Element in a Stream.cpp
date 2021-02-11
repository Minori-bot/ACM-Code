class KthLargest {
private:
    int k, cnt;
    static const int N = 100005;
    int ch[N][2], val[N], siz[N], num[N], fa[N], root, tot;
    
    inline int newNode(int p, int v){
        val[++tot] = v, fa[tot] = p;
        siz[tot] = num[tot] = 1, ch[tot][0] = ch[tot][1] = 0;
        return tot;
    }
    
    inline void push_up(int x){
        siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + num[x];
    }
    
    inline void rotate(int x){
        int y = fa[x], z = fa[y], p = (ch[y][1] == x) ^ 1;
        ch[y][p^1] = ch[x][p], fa[ch[x][p]] = y;
        fa[x] = z, ch[z][ch[z][1] == y] = x, fa[y] = x, ch[x][p] = y;
        push_up(y), push_up(x);
    }
    
    inline void splay(int x, int goal=0){
        if(x == goal) return;
        while(fa[x] != goal){
            int y = fa[x], z = fa[y];
            if(z != goal){
                (ch[y][0] == x) ^ (ch[z][0] == y) ? rotate(x) : rotate(y);
            }
            rotate(x);
        }
        push_up(x);
        if(goal == 0) root = x;
    }
    
    void insert(int x){
        if(!root){
            root = newNode(0, x);
            return;
        }
        int cur = root;
        while(ch[cur][x > val[cur]]){
            if(val[cur] == x) break;
            cur = ch[cur][x > val[cur]];
        }
        if(val[cur] == x) siz[cur] ++, num[cur] ++, splay(cur);
        else ch[cur][x > val[cur]] = newNode(cur, x), splay(ch[cur][x > val[cur]]);
    }
    
    int select(int k){
        int cur = root, m = siz[ch[cur][0]];
        while(1){
            if(k > m + num[cur]){
                k -= m + num[cur];
                cur = ch[cur][1];
            }
            else{
                if(m >= k) cur = ch[cur][0];
                else return val[cur];
            }
            m = siz[ch[cur][0]];
        }
    }
    
public:
    KthLargest(int k, vector<int>& nums) {
        
        this->k = k;
        cnt = 0;
        for(auto e: nums){
            insert(e);
            cnt ++;
        }
    }

    int add(int val) {
        
        insert(val);
        cnt ++;
        return select(cnt - k + 1);
    }
};