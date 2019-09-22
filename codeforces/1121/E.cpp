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
int _, a, b;
string s;
vector<int> v;

void calc(){
    v.clear();
    for(int l = 0, r = 0; l < s.size();){
        if(s[l] == 'X'){
            l ++;
            continue;
        }
        r = l;
        while(r < s.size() && s[r] == '.') r ++;
        v.pb(r - l);
        l = r;
    }
}

bool solve(){
    int p = -1, cnt = 0;
    for(int i = 0; i < v.size(); i ++){
        if(v[i] >= b && v[i] < a) return false;
        if(v[i] >= 2 * b){
            if(p == -1) p = i;
            else return false;
        }
        if(v[i] >= a && v[i] < 2 * b) cnt ++;
    }
    if(p == -1){
        return cnt % 2 != 0;
    }
    int t = v[p];
    for(int x = 0; x + a <= t; x ++){
        int y = t - x - a, ncnt = cnt;
        if((x >= b && x < a) || x >= 2 * b) continue;
        if((y >= b && y < a) || y >= 2 * b) continue;
        if(x >= a && x < 2 * b) ncnt ++;
        if(y >= a && y < 2 * b) ncnt ++;
        if(ncnt % 2 == 0) return true;
    }
    return false;
}

int main(){

    __fastIn;

    for(cin >> _; _; _ --){
        cin >> a >> b >> s;
        calc();
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}