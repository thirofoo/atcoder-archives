/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc126/submissions/37708845
 * Submitted at: 2023-01-03 15:24:24
 * Problem URL: https://atcoder.jp/contests/abc126/tasks/abc126_e
 * Result: AC
 * Execution Time: 37 ms
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
    dsu uf(n);
    rep(i,m){
        ll x,y,z; input(x,y,z);
        x--; y--;
        uf.merge(x,y);
    }
    vector g = uf.groups();
    print(g.size());
    
    return 0;
}