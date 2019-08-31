#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define full(a, b) memset(a, b, sizeof a)
#define __fastIn ios::sync_with_stdio(false), cin.tie(0)
#define pb push_back
using namespace std;
using LL = long long;
inline int lowbit(int x){ return x & (-x); }
inline int read(){
    int ret = 0, w = 0; char ch = 0;
    while(!isdigit(ch)){
        w |= ch == '-', ch = getchar();
    }
    while(isdigit(ch)){
        ret = (ret << 3) + (ret << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -ret : ret;
}
template <typename A>
inline A __lcm(A a, A b){ return a / __gcd(a, b) * b; }
template <typename A, typename B, typename C>
inline A fpow(A x, B p, C lyd){
    A ans = 1;
    for(; p; p >>= 1, x = 1LL * x * x % lyd)if(p & 1)ans = 1LL * x * ans % lyd;
    return ans;
}
const int N = 2000;
const int M = 300005;
int n, cnt, t, maxlen, bel[M];
char str[N];
bool vis[N];
namespace SuffixArray{

    char s[M];
    int sa[M], t[M], t2[M], c[M], height[M], rank[M];

    void init(){
        full(height, 0), full(rank, 0);
        full(sa, 0), full(t, 0), full(t2, 0);
    }

    void build(int m, int n){
        int *x = t, *y = t2;
        for(int i = 0; i < m; i ++) c[i] = 0;
        for(int i = 0; i < n; i ++) c[x[i] = s[i]] ++;
        for(int i = 0; i < m; i ++) c[i] += c[i - 1];
        for(int i = n - 1; i >= 0; i --) sa[--c[x[i]]] = i;
        for(int k = 1; k <= n; k <<= 1){
            int p = 0;
            for(int i = n - k; i < n; i ++) y[p++] = i;
            for(int i = 0; i < n; i ++){
                if(sa[i] >= k) y[p++] = sa[i] - k;
            }
            for(int i = 0; i < m; i ++) c[i] = 0;
            for(int i = 0; i < n; i ++) c[x[y[i]]] ++;
            for(int i = 0; i < m; i ++) c[i] += c[i - 1];
            for(int i = n - 1; i >= 0; i --) sa[--c[x[y[i]]]] = y[i];
            swap(x, y);
            p = 1, x[sa[0]] = 0;
            for(int i = 1; i < n; i ++){
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && sa[i - 1] + k < n &&
                           sa[i] + k < n && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p ++;
            }
            if(p >= n) break;
            m = p;
        }

        int k = 0;
        for(int i = 0; i < n; i ++) rank[sa[i]] = i;
        for(int i = 0; i < n; i ++){
            if(!rank[i]) continue;
            if(k) k --;
            int j = sa[rank[i] - 1];
            while(i + k < n && j + k < n && s[i + k] == s[j + k]) k ++;
            height[rank[i]] = k;
        }
    }
}

using SuffixArray::height;
using SuffixArray::sa;

bool calc(int len, int p){
    full(vis, false);
    int cur = 0;
    if(bel[sa[0]]) vis[bel[sa[0]]] = true, cur ++;
    for(int i = 1; i < len; i ++){
        if(height[i] >= p){
            if(!vis[bel[sa[i]]] && bel[sa[i]]) vis[bel[sa[i]]] = true, cur ++;
        }
        else{
            full(vis, false);
            cur = 0;
            if(!vis[bel[sa[i]]] && bel[sa[i]]) vis[bel[sa[i]]] = true, cur ++;
        }
        if(cur >= t) return true;
    }
    return false;
}

void get(int len, int p){
    full(vis, false);
    int cur = 0;
    if(bel[sa[0]]) vis[bel[sa[0]]] = true, cur ++;
    for(int i = 1; i < len; i ++){
        if(height[i] >= p){
            if(!vis[bel[sa[i]]] && bel[sa[i]]) vis[bel[sa[i]]] = true, cur ++;
        }
        else{
            if(cur >= t){
                for(int j = sa[i - 1]; j < sa[i - 1] + p; j ++){
                    printf("%c", SuffixArray::s[j]);
                }
                puts("");
            }
            cur = 0;
            full(vis, false);
            if(!vis[bel[sa[i]]] && bel[sa[i]]) vis[bel[sa[i]]] = true, cur ++;
        }
    }
    if(cur >= t){
        for(int j = sa[len - 1]; j < sa[len - 1] + p; j ++){
            printf("%c", SuffixArray::s[j]);
        }
        puts("");
    }
}

void solve(int len){

    int l = 0, r = maxlen;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(calc(len, mid)) l = mid;
        else r = mid - 1;
    }
    if(l == 0) puts("?");
    else get(len, l);
}

int main(){

    int f = 1;
    while(~scanf("%d", &n) && n){
        if(!f) puts("");
        else f = 0;
        cnt = 1, t = n / 2 + 1, maxlen = 0;
        full(bel, 0);
        int pos = 0;
        for(int i = 1; i <= n; i ++){
            scanf("%s", str);
            int m = strlen(str);
            maxlen = max(m, maxlen);
            for(int j = 0; j < m; j ++){
                SuffixArray::s[pos + j] = str[j];
                bel[pos + j] = i;
            }
            SuffixArray::s[pos + m] = cnt ++;
            pos = pos + m + 1;
        }
        SuffixArray::init();
        SuffixArray::build(150, (int)strlen(SuffixArray::s));
        solve((int)strlen(SuffixArray::s));
    }
    return 0;
}