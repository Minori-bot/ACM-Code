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
const int N = 200005;
const double Pi = acos(-1.0);
int n, len = 1, k, x[N], y[N], r[N], z[N];
string A, B;
struct Complex{
    double x, y;
    Complex(){
        x = 0.0, y = 0.0;
    }
    Complex(double x, double y): x(x), y(y){}
    Complex operator + (const Complex &b) const {
        return Complex(x + b.x, y + b.y);
    }
    Complex operator - (const Complex &b) const {
        return Complex(x - b.x, y - b.y);
    }
    Complex operator * (const Complex &b) const {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
}a[N], b[N], c[N];

void fft(Complex y[], int len, int type){
    for(int i = 0; i < len; i ++){
        if(i < r[i]) swap(y[i], y[r[i]]);
    }
    for(int k = 2; k <= len; k <<= 1){
        Complex wn = Complex(cos(2 * Pi / k), type * sin(2 * Pi / k));
        for(int i = 0; i < len; i += k){
            Complex w = Complex(1, 0);
            for(int j = i; j < i + k / 2; j ++){
                Complex u = y[j];
                Complex t = w * y[j + k / 2];
                y[j] = u + t, y[j + k / 2] = u - t;
                w = w * wn;
            }
        }
    }
}

void solve(){
    int s = 2 * n;
    for(int i = 0; i <= s; i ++){
        if(z[i] >= 10) z[i + 1] += z[i] / 10, z[i] %= 10, s += (i == s);
    }
    int cur = s;
    while(cur > 0 && !z[cur]) cur --;
    if(!z[cur]) cout << "0" << endl;
    else{
        for(int i = cur; i >= 0; i --){
            cout << z[i];
        }
        cout << endl;
    }
}

int main(){

    __fastIn;

    cin >> n >> A >> B;
    n --;
    for(int i = 0; i <= n; i ++) x[i] = A[n - i] - '0';
    for(int i = 0; i <= n; i ++) y[i] = B[n - i] - '0';
    while(len <= (n << 1)) len <<= 1, k ++;
    for(int i = 0; i <= n; i ++){
        a[i] = Complex(x[i], 0);
        b[i] = Complex(y[i], 0);
    }
    for(int i = n + 1; i < len; i ++){
        a[i] = Complex();
        b[i] = Complex();
    }
    for(int i = 0; i < len; i ++){
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (k - 1));
    }
    fft(a, len, 1);
    fft(b, len, 1);
    for(int i = 0; i < len; i ++){
        c[i] = a[i] * b[i];
    }
    fft(c, len, -1);
    for(int i = 0; i <= 2 * n; i ++){
        z[i] = (int)(round(c[i].x / len));
    }
    solve();

    return 0;
}