/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc164/submissions/43422369
 * Submitted at: 2023-07-09 21:25:35
 * Problem URL: https://atcoder.jp/contests/arc164/tasks/arc164_b
 * Result: WA
 * Execution Time: 61 ms
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
    
    // 黒黒 || 白白 で 100% OK
    // それ以外 → 基本無理そう…？

    ll n,m; input(n,m);
    vector<P> edge;
    rep(i,m){
        ll a, b; input(a,b);
        a--; b--;
        edge.push_back(P(a,b));
    }
    vector<ll> c(n);
    rep(i,n) input(c[i]);
    rep(i,m){
        auto [a,b] = edge[i];
        if( c[a] == c[b] ){
            print("Yes");
            return 0;
        }
    }
    print("No");
    
    return 0;
}