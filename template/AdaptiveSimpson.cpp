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
double a, b, c, d, l, r;

double f(double x){
    double w = c * x + d, v = a * x + b;
    return w / v;
}

double simpson(double a, double b){
    double c = a + (b - a) / 2;
    return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6;
}

double asr(double a, double b, double eps, double t){
    double c = a + (b - a) / 2;
    double L = simpson(a, c), R = simpson(c, b);
    if(fabs(L + R - t) <= 15 * eps) return L + R - (L + R - t) / 15;
    return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);
}

double asr(double a, double b, double eps){
    return asr(a, b, eps, simpson(a, b));
}

int main(){

    __fastIn;

    cin >> a >> b >> c >> d >> l >> r;
    printf("%.6lf\n", asr(l, r, 1e-8));

    return 0;
}