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

const int N = 5e6 + 10;
int n;
vector<int> num;
vector<pii> record[N];

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);

    cin >> n;
    num.resize(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> num[i];
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; i + j <= n; j ++){
            int val = num[j] + num[i + j];
            for(auto& p: record[val]){
                if(p.first != j && p.first != i + j && p.second != j && p.second != i + j){
                    cout << "YES" << endl;
                    cout << p.first << " " << p.second << " " << j << " " << i + j << endl;
                    return 0;
                }
            }
            record[val].emplace_back(j, i +j);
        }
    }
    cout << "NO" << endl;

    return 0;
}
