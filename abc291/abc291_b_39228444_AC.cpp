/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc291/submissions/39228444
 * Submitted at: 2023-02-26 21:03:07
 * Problem URL: https://atcoder.jp/contests/abc291/tasks/abc291_b
 * Result: AC
 * Execution Time: 7 ms
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
    cout << setprecision(10) << fixed;
    
    ll n; input(n);
    vector<ll> x(5*n);
    rep(i,5*n)input(x[i]);
    sort(x.begin(),x.end());
    ld ans = 0;
    for(ll i=n;i<4*n;i++)ans += x[i];
    print(ans/(3*n));
    
    return 0;
}