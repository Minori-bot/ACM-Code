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
const int N = 5000005;
int _, n, tot, prime[N];
LL phi[N], mu[N];
bool vis[N];
unordered_map<int, LL> a, b;

void sieve(){
    mu[1] = phi[1] = 1;
    for(int i = 2; i < N; i ++){
        if(!vis[i]){
            prime[++tot] = i;
            phi[i] = i - 1, mu[i] = -1;
        }
        for(int j = 1; j <= tot && i * prime[j] < N; j ++){
            vis[i * prime[j]] = true;
            if(i % prime[j] == 0){
                mu[i * prime[j]] = 0;
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else{
                mu[i * prime[j]] = -mu[i];
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    for(int i = 1; i < N; i ++){
        phi[i] = phi[i - 1] + phi[i];
        mu[i] = mu[i - 1] + mu[i];
    }
}

LL calcPhi(int n){
    if(n < N) return phi[n];
    if(a[n]) return a[n];
    LL ans = (1LL + n) * n / 2;
    for(int l = 2, r; l <= n; l = r + 1){
        r = n / (n / l);
        ans -= (r - l + 1) * calcPhi(n / l);
    }
    a[n] = ans;
    return ans;
}

LL calcMu(int n){
    if(n < N) return mu[n];
    if(b[n]) return b[n];
    LL ans = 1;
    for(int l = 2, r; l <= n; l = r + 1){
        r = n / (n / l);
        ans -= (r - l + 1) * calcMu(n / l);
    }
    b[n] = ans;
    return ans;
}

int main(){

    sieve();
    for(_ = read(); _; _ --){
        n = read();
        printf("%lld %lld\n", calcPhi(n), calcMu(n));
    }
    return 0;
}