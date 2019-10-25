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
const int N = 400005;
int n, a[N], ans[N];
multiset<int> s;
 
int main(){
 
    n = read();
    for(int i = 1; i <= n; i ++){
        a[i] = read(), a[i + n] = a[i + 2 * n] = a[i];
    }
    int p = 1;
    for(int i = 1; i <= n; i ++){
        while(p <= n * 3){
            if(!s.empty()){
                int cur = *s.rbegin();
                if((cur & 1 && a[p] <= cur / 2) || a[p] < cur / 2) break;
            }
            s.insert(a[p]), p ++;
        }
        if(p >= n * 3) ans[i] = -1;
        else{
            ans[i] = p - i;
            s.erase(s.find(a[i]));
        }
    }
    for(int i = 1; i <= n; i ++){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}