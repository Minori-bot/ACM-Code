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
const int N = 10005;
int _, n, m, cs;
LL a[N], k;

namespace XorBasis{

    bool zero = false;
    int t = 0;

    void init(){
        zero = false, t = 0;
    }

    void build(){
        t = n;
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                if(a[j] > a[i]) swap(a[j], a[i]);
            }
            if(a[i] == 0){
                zero = true, t = i - 1;
                break;
            }
            for(int k = 63; k >= 0; k --){
                if(a[i] & (1LL << k)){
                    for(int j = 1; j <= n; j ++){
                        if(i != j && a[j] & (1LL << k)) a[j] ^= a[i];
                    }
                    break;
                }
            }
        }
    }

    LL query(LL k){
        LL ret = 0;
        for(int i = t - 1; i >= 0; i --){
            if(k & (1LL << i)) ret ^= a[t - i];
        }
        return ret;
    }
    
    LL sum(){
        LL ret = 0;
        for(int i = t; i >= 1; i --){
            ret ^= a[i];
        }
        return ret;
    }
}

using XorBasis::build;
using XorBasis::zero;
using XorBasis::t;
using XorBasis::query;

int main(){

    for(scanf("%d", &_); _; _ --){
        XorBasis::init();
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &a[i]);
        }
        build();
        scanf("%d", &m);
        printf("Case #%d:\n", ++cs);
        while(m --){
            scanf("%lld", &k);
            if(zero) k --;
            if(k >= (1LL << t)) puts("-1");
            else printf("%lld\n", query(k));
        }
    }
    return 0;
}