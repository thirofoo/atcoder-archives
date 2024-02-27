/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc282/submissions/50672901
 * Submitted at: 2024-02-27 12:04:35
 * Problem URL: https://atcoder.jp/contests/abc282/tasks/abc282_e
 * Result: WA
 * Execution Time: 3150 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // 玉は 1 個ずつ減っていく ⇒ 食べる順番は貪欲で良さそう
    mint::set_mod(m);
    vector<vector<mint>> r(n,vector<mint>(n,0));
    rep(i,n) reps(j,i+1,n) {
        r[i][j] = mint(a[i]).pow(a[j]) + mint(a[j]).pow(a[i]);
        r[j][i] = r[i][j];
    }
    ll ans = 0;
    vector<bool> ate(n,false);
    rep(i,n-1) {
        // 一番スコアが高い & 将来性の無い玉を食べる
        vector<vector<ll>> score(n);
        rep(j,n) {
            if( ate[j] ) continue;
            rep(k,n) {
                if( ate[k] ) continue;
                score[j].emplace_back(r[j][k].val());
                score[k].emplace_back(r[j][k].val());
            }
        }
        rep(j,n) sort(score[j].begin(), score[j].end(), greater<ll>());
        vector<ll> p;
        rep(j,n) if( !ate[j] ) p.emplace_back(j);
        sort(p.begin(), p.end(), [&](ll ni, ll nj) {
            vector<ll> &a = score[ni], &b = score[nj];
            ll size = min(a.size(),b.size());
            if( size == 0 ) return a.size() > b.size();
            if( a[0] != b[0] ) return a[0] > b[0];
            reps(k,1,size) if( a[k] != b[k] ) return a[k] < b[k];
            return a.size() < b.size();
        });
        ans += score[p[0]][0];
        ate[p[0]] = true;
    }
    cout << ans << endl;
    
    return 0;
}