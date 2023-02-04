/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc288/submissions/38612780
 * Submitted at: 2023-02-04 21:23:13
 * Problem URL: https://atcoder.jp/contests/abc288/tasks/abc288_c
 * Result: AC
 * Execution Time: 47 ms
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
    ll ans = 0;
    rep(i,m){
        ll a,b; input(a,b);
        a--; b--;
        if(!uf.same(a,b)){
            uf.merge(a,b);
        }
        else ans++;
    }
    print(ans);
    
    return 0;
}