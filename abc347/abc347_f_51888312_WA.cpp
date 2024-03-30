/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc347/submissions/51888312
 * Submitted at: 2024-03-31 00:43:22
 * Problem URL: https://atcoder.jp/contests/abc347/tasks/abc347_f
 * Result: WA
 * Execution Time: 3334 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

// S:実 F:遅延
using S = struct {
  ll size;
  ll val;
};
using F = ll;
// operator (作用素)
S op(S l,S r) {
  return {l.size+r.size, max(l.val, r.val)};
}
// 遅延データ反映
S mapping(F f,S x) {
  return {x.size, max(x.val, f)};
}
// 遅延データ作用 ※ f(g(x))
F composition(F f,F g) {
  return max(f, g);
}
S e() { return {0, 0}; } // 単位元 (op(e, a) = op(a, e) = a)
F id() { return 0; } // 恒等写像 (mapping(id, a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n+1, vector<ll>(n+1, 0));
    rep(i,n) rep(j,n) cin >> a[i+1][j+1];
    rep(i,n+1) rep(j,n) a[i][j+1] += a[i][j];
    rep(i,n) rep(j,n+1) a[i+1][j] += a[i][j];
    vector<vector<ll>> rect(n+1, vector<ll>(n+1, 0));
    rep(i,n+1) rep(j,n+1) {
        if( i-m < 0 || j-m < 0 ) continue;
        rect[i][j] = a[i][j]-a[i-m][j]-a[i][j-m]+a[i-m][j-m];
    }
    vector seg(n+1, vector(4, lazy_segtree<S,op,e,F,mapping,composition,id>(n+1)));
    vector dp(n+1, vector(4, lazy_segtree<S,op,e,F,mapping,composition,id>(n+1)));
    // dp[i][j][k] : (i,k) までみて j 個採用のときの最大値
    // ※ seg は dp の値を列として持つ
    vector<ll> pre_max(3,0);
    reps(i,m,n+1) {
        vector<ll> col_max(3,0);
        reps(j,m,n+1) {
            rep(k,3) {
                // 採用する時
                dp[i][k+1].set(j, {1, max( max(pre_max[k], col_max[k]) + rect[i][j], dp[i][k+1].get(j).val )});
                seg[j][k+1].set(i, {1, max(dp[i][k+1].get(j).val, seg[j][k+1].get(i).val)});
                col_max[k] = max(col_max[k], seg[j-m+1][k].prod(0, i+1).val);
            }
        }
        rep(k,3) pre_max[k] = dp[i-m+1][k].all_prod().val;
    }
    pre_max = {0,0,0};
    reps(i,m,n+1) {
        vector<ll> col_max(3,0);
        for(ll j=n; j>=m; j--) {
            rep(k,3) {
                // 採用する時
                dp[i][k+1].set(j, {1, max( max(pre_max[k], col_max[k]) + rect[i][j], dp[i][k+1].get(j).val )});
                seg[j][k+1].set(i, {1, max(dp[i][k+1].get(j).val, seg[j][k+1].get(i).val)});
                if( j+m-1 <= n ) col_max[k] = max(col_max[k], seg[j+m-1][k].prod(0, i+1).val);
            }
        }
        rep(k,3) pre_max[k] = dp[i-m+1][k].all_prod().val;
    }
    pre_max = {0,0,0};
    reps(i,m,n+1) {
        vector<ll> col_max(3,0);
        reps(j,m,n+1) {
            rep(k,3) {
                // 採用する時
                dp[i][k+1].set(j, {1, max( max(pre_max[k], col_max[k]) + rect[i][j], dp[i][k+1].get(j).val )});
                seg[j][k+1].set(i, {1, max(dp[i][k+1].get(j).val, seg[j][k+1].get(i).val)});
                col_max[k] = max(col_max[k], seg[j-m+1][k].prod(0, i+1).val);
            }
        }
        rep(k,3) pre_max[k] = dp[i-m+1][k].all_prod().val;
    }
    pre_max = {0,0,0};
    reps(i,m,n+1) {
        vector<ll> col_max(3,0);
        for(ll j=n; j>=m; j--) {
            rep(k,3) {
                // 採用する時
                dp[i][k+1].set(j, {1, max( max(pre_max[k], col_max[k]) + rect[i][j], dp[i][k+1].get(j).val )});
                seg[j][k+1].set(i, {1, max(dp[i][k+1].get(j).val, seg[j][k+1].get(i).val)});
                if( j+m-1 <= n ) col_max[k] = max(col_max[k], seg[j+m-1][k].prod(0, i+1).val);
            }
        }
        rep(k,3) pre_max[k] = dp[i-m+1][k].all_prod().val;
    }
    ll ans = 0;
    rep(i,n+1) rep(j,n+1) ans = max(ans, dp[i][3].get(j).val);
    cout << ans << '\n';
    
    return 0;
}