/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc079/submissions/34853153
 * Submitted at: 2022-09-14 19:03:25
 * Problem URL: https://atcoder.jp/contests/abc079/tasks/abc079_d
 * Result: AC
 * Execution Time: 15 ms
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
    
    ll h,w; input(h,w);
    vector cost(10,vector<ll>(10));
    rep(i,10)rep(j,10)input(cost[i][j]);
    rep(k,10)rep(j,10)rep(i,10)cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
    vector field(h,vector<ll>(w));
    rep(i,h)rep(j,w)input(field[i][j]);
    ll ans = 0;
    rep(i,h)rep(j,w)if(field[i][j] != -1)ans += cost[field[i][j]][1];
    print(ans);
    
    return 0;
}