/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc241/submissions/49809264
 * Submitted at: 2024-01-30 17:31:39
 * Problem URL: https://atcoder.jp/contests/abc241/tasks/abc241_e
 * Result: AC
 * Execution Time: 99 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll dep = 60;
    vector<vector<ll>> d(dep,vector<ll>(n,0));
    d[0] = a;
    // d[i][j] : 初め modN で j 個皿に載ってる時に 2^i 回操作した後の飴の個数
    rep(i,dep-1) rep(j,n) d[i+1][j] = d[i][j] + d[i][(j+d[i][j])%n];
    ll ans = 0;
    rep(i,60) {
        if( !(k & (1LL << i)) ) continue;
        ans += d[i][ans%n];
    }
    cout << ans << endl;
    
    return 0;
}