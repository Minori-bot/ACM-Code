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
const int N = 100005;
int n, m, rev[N], a, b;
deque<int> dq[N];

int getLast(int a){
    if(rev[a]) return dq[a].front();
    return dq[a].back();
}

int getFirst(int a){
    if(rev[a]) return dq[a].back();
    return dq[a].front();
}

void removeLast(int a){
    if(rev[a]) dq[a].pop_front();
    else dq[a].pop_back();
}

void addLast(int a, int val){
    if(rev[a]) dq[a].push_front(val);
    else dq[a].push_back(val);
}

void removeFirst(int a){
    if(rev[a]) dq[a].pop_back();
    else dq[a].pop_front();
}

void addFirst(int a, int val){
    if(rev[a]) dq[a].push_back(val);
    else dq[a].push_front(val);
}

int main(){

    while(~scanf("%d%d", &n, &m)){
        for(int i = 1; i <= n; i ++){
            dq[i].clear(), rev[i] = 0;
            dq[i].push_back(i);
        }
        while(m --){
            scanf("%d%d", &a, &b);
            if(dq[a].size() >= dq[b].size()){
                while(!dq[b].empty()){
                    addLast(a, getFirst(b));
                    removeFirst(b);
                }
                rev[a] ^= 1, rev[b] ^= 1;
            }
            else{
                while(!dq[a].empty()){
                    addFirst(b, getLast(a));
                    removeLast(a);
                }
                rev[a] = (rev[b] ^ 1), rev[b] ^= 1;
                swap(dq[a], dq[b]);
            }
        }
        printf("%d", dq[1].size());
        if(rev[1]){
            while(!dq[1].empty()) printf(" %d", dq[1].back()), dq[1].pop_back();
        }
        else{
            while(!dq[1].empty()) printf(" %d", dq[1].front()), dq[1].pop_front();
        }
        puts("");
    }
    return 0;
}