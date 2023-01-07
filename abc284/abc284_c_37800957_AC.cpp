/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc284/submissions/37800957
 * Submitted at: 2023-01-07 21:04:50
 * Problem URL: https://atcoder.jp/contests/abc284/tasks/abc284_c
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
    dsu uf(n);
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        uf.merge(u,v);
    }
    vector<vector<int>> g = uf.groups();
    print(g.size());
    
    return 0;
}