#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
using namespace std;
using LL = long long;
using pii = pair<int, int>;

inline int lowbit(int x) { return x & (-x); }
template <typename A>
inline A __lcm(A a, A b){ return a / __gcd(a, b) * b; }
template <typename A, typename B, typename C>
inline A fpow(A x, B p, C lyd) {
    A ans = 1;
    for(; p; p >>= 1, x = 1LL * x * x % lyd)if(p & 1)ans = 1LL * x * ans % lyd;
    return ans;
}

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

int n, m, cnt;
vector<int> a;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);

	cin >> n >> m;
	a.resize(n + 1);
	for(int i = 1; i <= n; i ++){
	    cin >> a[i];
	    cnt += a[i];
	}
	while(m --){
	    int x, k;
	    cin >> x >> k;
	    if(x == 1){
	        if(a[k]) cnt --, a[k] = 0;
	        else cnt ++, a[k] = 1;
	    }
	    else{
	        if(k <= cnt) cout << "1" << endl;
	        else cout << "0" << endl;
	    }
	}

	return 0;
}
