/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc310/submissions/43582202
 * Submitted at: 2023-07-15 21:01:26
 * Problem URL: https://atcoder.jp/contests/abc310/tasks/abc310_a
 * Result: AC
 * Execution Time: 14 ms
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
    
    ll n,p,q; input(n,p,q);
    ll ans = p;
    vector<ll> d(n);
    rep(i,n)input(d[i]);
    sort(d.begin(),d.end());
    ans = min(ans,d[0]+q);
    print(ans);
    
    return 0;
}