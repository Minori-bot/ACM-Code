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
LL n, p, phi[N], inv4, inv6, inv2, k;
int tot, prime[N];
bool vis[N];
unordered_map<LL, LL> m;

void sieve(){
    phi[1] = 1;
    for(int i = 2; i <= k; i ++){
        if(!vis[i]){
            prime[++tot] = i, phi[i] = (i - 1) % p;
        }
        for(int j = 1; j <= tot && i * prime[j] <= k; j ++){
            vis[i * prime[j]] = true;
            if(i % prime[j] == 0){
                phi[i * prime[j]] = phi[i] * prime[j] % p;
                break;
            }
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1) % p;
        }
    }
    for(int i = 1; i <= k; i ++){
        phi[i] = (phi[i - 1] + phi[i] * i % p * i % p) % p;
    }
}

LL fg(LL n){
    n %= p;
    return n * n % p * (n + 1) % p * (n + 1) % p * inv4 % p;
}

LL g(LL n){
    n %= p;
    return n * (n + 1) % p * (n + n + 1) % p * inv6 % p;
}

LL h(LL n){
    n %= p;
    return (n + 1) * n % p * inv2 % p;
}

LL calc(LL n){
    if(n <= k) return phi[n];
    if(m[n]) return m[n];
    LL ans = fg(n);
    for(LL l = 2, r; l <= n; l = r + 1){
        r = n / (n / l);
        LL t = (g(r) + p - g(l - 1)) % p * calc(n / l) % p;
        ans = (ans + p - t) % p;
    }
    m[n] = ans;
    return ans;
}

LL solve(){
    LL ans = 0;
    for(LL l = 1, r; l <= n; l = r + 1){
        r = n / (n / l);
        LL t = h(n / l);
        t = t * t % p;
        ans = (ans % p + t * ((calc(r) + p - calc(l - 1)) % p) % p) % p;
    }
    return ans;
}

int main(){

    scanf("%lld%lld", &p, &n);
    k = min(1LL * N - 5, n);
    inv2 = fpow(2, p - 2, p);
    inv4 = fpow(4, p - 2, p);
    inv6 = fpow(6, p - 2, p);
    sieve();
    printf("%lld\n", solve());

    return 0;
}