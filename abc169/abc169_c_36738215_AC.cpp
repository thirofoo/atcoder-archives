/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc169/submissions/36738215
 * Submitted at: 2022-11-23 19:43:37
 * Problem URL: https://atcoder.jp/contests/abc169/tasks/abc169_c
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ld a,b; input(a,b);
    // 誤差を無くすには整数で演算。
    print((ll)(a*round(b*100))/100);
    
    return 0;
}