/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc309/submissions/43353382
 * Submitted at: 2023-07-08 21:17:34
 * Problem URL: https://atcoder.jp/contests/abc309/tasks/abc309_b
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
    
    ll n; input(n);
    vector<string> a(n), ans;
    rep(i,n)input(a[i]);
    ans = a;
    rep(i,n-1)ans[0][i+1] = a[0][i];
    rep(i,n-1)ans[i+1][n-1] = a[i][n-1];
    rep(i,n-1)ans[n-1][i] = a[n-1][i+1];
    rep(i,n-1)ans[i][0] = a[i+1][0];
    rep(i,n)print(ans[i]);
    
    return 0;
}