/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc308/submissions/43097368
 * Submitted at: 2023-07-01 21:08:24
 * Problem URL: https://atcoder.jp/contests/abc308/tasks/abc308_b
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
    
    ll n,m; input(n,m);
    vector<string> c(n), d(m);
    vector<ll> p(m+1);
    rep(i,n)input(c[i]);
    rep(i,m)input(d[i]);
    rep(i,m+1)input(p[i]);
    map<string,ll> v;
    rep(i,m)v[d[i]] = p[i+1];
    ll ans = 0;
    rep(i,n){
        if(v.count(c[i]))ans += v[c[i]];
        else ans += p[0];
    }
    print(ans);
    
    return 0;
}