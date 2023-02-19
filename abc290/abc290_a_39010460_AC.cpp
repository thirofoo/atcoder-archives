/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc290/submissions/39010460
 * Submitted at: 2023-02-19 21:01:28
 * Problem URL: https://atcoder.jp/contests/abc290/tasks/abc290_a
 * Result: AC
 * Execution Time: 6 ms
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
    
    ll n,m; input(n,m);
    vector<ll> a;
    rep(i,n){
        ll t; input(t);
        a.push_back(t);
    }
    ll ans = 0;
    rep(i,m){
        ll q; input(q);
        ans += a[q-1];
    }
    print(ans);
    
    return 0;
}