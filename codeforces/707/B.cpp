#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define full(a, b) memset(a, b, sizeof a)
#define __fastIn ios::sync_with_stdio(false), cin.tie(0)
#define pb push_back
using namespace std;
using LL = long long;
inline int lowbit(int x) { return x & (-x); }
inline int read() {
    int ret = 0, w = 0; char ch = 0;
    while(!isdigit(ch)) {
        w |= ch == '-', ch = getchar();
    }
    while(isdigit(ch)) {
        ret = (ret << 3) + (ret << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -ret : ret;
}
template <typename A>
inline A __lcm(A a, A b){ return a / __gcd(a, b) * b; }
template <typename A, typename B, typename C>
inline A fpow(A x, B p, C lyd) {
    A ans = 1;
    for(; p; p >>= 1, x = 1LL * x * x % lyd)if(p & 1)ans = 1LL * x * ans % lyd;
    return ans;
}
int _, n;
int main(){

    for(scanf("%d", &_); _; _ --){
        scanf("%d", &n);
        vector<int> cake(n, 0);
        vector<int> cream(n, 0);
        for(int i = 0; i < n; i ++){
            scanf("%d", &cream[i]);
        }
        vector<pair<int, int>> range;
        auto prior = make_pair(-1, -1);
        for(int i = 0; i < n; i ++){
            if(cream[i]){
                if(prior.first == -1){
                    prior.first = max(i - cream[i] + 1, 0);
                    prior.second = i;
                }
                else if(max(i - cream[i] + 1, 0)<= prior.second){
                    prior.first = min(prior.first, max(i - cream[i] + 1, 0));
                    prior.second = i;
                }
                else{
                    range.pb(prior);
                    prior.first = max(i - cream[i] + 1, 0);
                    prior.second = i;
                }
            }
        }
        range.pb(prior);
        for(auto& p: range){
            for(int i = p.first; i <= p.second; i ++){
                cake[i] = 1;
            }
        }
        for(int i = 0; i < n; i ++){
            printf("%d%c", cake[i], " \n"[i == n - 1]);
        }
    }

    return 0;
}

//1
//20
//0 0 0 5 1 0 0 0 0 0 0 0 0 1 0 0 0 0 4 2