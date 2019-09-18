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
int _, a, b, c;
 
int main(){
 
    for(scanf("%d", &_); _; _ --){
        scanf("%d%d%d", &a, &b, &c);
        if(a <= b){
            int x = a, y = b;
            a += min(c, y - x + 1), c -= min(y - x + 1, c);
        }
        if(c == 0 && a <= b) puts("0");
        else{
            int t = a + b + c;
            if(t & 1){
                t = t / 2 + 1;
                printf("%d\n", min(a + c - t + 1, c + 1));
            }
            else{
                t = t / 2;
                printf("%d\n", min(a + c - t, c + 1));
            }
        }
    }
    return 0;
}
