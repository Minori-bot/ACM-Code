
class Solution {
    const static int N = 300005;
    const static long long INF = 9223372036854775807;
private:

    double getMedian(bool odd, int k){

        if(odd){
            return select((k + 1) / 2 + 1);
        }
        else{
            int x = select(k / 2 + 1);
            int y = select(k / 2 + 2);
            cout << x << " " << y << endl;
            return (1LL * x + 1LL * y) / 2.0;
        }
    }
    
    int ch[N][2], siz[N], num[N], fa[N], root, tot;
    long long val[N];

    int newNode(int p, long long v){
        val[++tot] = v, fa[tot] = p;
        siz[tot] = num[tot] = 1, ch[tot][0] = ch[tot][1] = 0;
        return tot;
    }

    void push_up(int x){
        siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + num[x];
    }

    void rotate(int x){
        int y = fa[x], z = fa[y], p = (ch[y][1] == x) ^ 1;
        ch[y][p^1] = ch[x][p], fa[ch[x][p]] = y;
        fa[x] = z, ch[z][ch[z][1] == y] = x, fa[y] = x, ch[x][p] = y;
        push_up(y), push_up(x);
    }

    void splay(int x, int goal){
        if(x == goal) return;
        while(fa[x] != goal){
            int y = fa[x], z = fa[y];
            if(z != goal){
                if((ch[y][0] == x) ^ (ch[z][0] == y)) rotate(x);
                else rotate(y);
            }
            rotate(x);
        }
        push_up(x);
        if(goal == 0) root = x;
    }

    void insert(long long x){
        if(!root){
            root = newNode(0, x);
            return;
        }
        int cur = root;
        while(ch[cur][x > val[cur]]){
            if(val[cur] == x) break;
            cur = ch[cur][x > val[cur]];
        }
        if(val[cur] == x) siz[cur] ++, num[cur] ++, splay(cur, 0);
        else ch[cur][x > val[cur]] = newNode(cur, x), splay(ch[cur][x > val[cur]], 0);
    }

    void find(long long x){
        if(!root) return;
        int cur = root;
        while(val[cur] != x && ch[cur][x > val[cur]])
            cur = ch[cur][x > val[cur]];
        splay(cur, 0);
    }

    int precursor(long long x){
        find(x);
        if(val[root] < x) return root;
        int cur = ch[root][0];
        while(ch[cur][1]) cur = ch[cur][1];
        return cur;
    }

    int successor(long long x){
        find(x);
        if(val[root] > x) return root;
        int cur = ch[root][1];
        while(ch[cur][0]) cur = ch[cur][0];
        return cur;
    }

    void del(long long x){
        int pre = precursor(x), suc = successor(x);
        splay(pre, 0), splay(suc, root);
        int key = ch[suc][0];
        if(num[key] > 1) num[key] --, siz[key] --, splay(key, 0);
        else ch[suc][0] = 0;
        push_up(suc), push_up(root);
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
    void inOrder(int x){
        if(!x) return;
        inOrder(ch[x][0]);
        cout << val[x] << " ";
        inOrder(ch[x][1]);
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        insert(INF);
        insert(-INF);
        bool odd = (k & 1);
        for(int i = 0; i < k; i ++){
            insert(nums[i]);
        }
        vector<double> res;

        int l = 0, r = k - 1;
        while(r < nums.size() - 1){
            res.push_back(getMedian(odd, k));
            del(nums[l++]);
            insert(nums[++r]);
        }
        res.push_back(getMedian(odd, k));

        return res;
    }
};