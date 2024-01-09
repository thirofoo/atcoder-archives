/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc335/submissions/49179432
 * Submitted at: 2024-01-09 17:14:43
 * Problem URL: https://atcoder.jp/contests/abc335/tasks/abc335_f
 * Result: AC
 * Execution Time: 273 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    // sqrt(N) を境界として方針を変えるとどちらも O(N√N) で解ける
    int v = sqrt(n);
    vector<mint> dp1(n);
    vector<vector<mint>> dp2(v+2,vector<mint>(v+2,0));
    // dp1[i] : i 番目まで見た時の黒の塗り方の総数
    // dp2[i][j] : 今までで i で割った時に余り j の時の黒の塗り方の総数
    dp1[0] = 1;
    rep(i,n) {
        // 過去の a <= v の時の塗り方を反映
        for(ll j=1; j<=v; j++) dp1[i] += dp2[j][i%j];

        // v を閾値にして方針を変えた DP
        if( a[i] <= v ) dp2[a[i]][i%a[i]] += dp1[i];
        else for(ll j=i+a[i]; j<n; j+=a[i]) dp1[j] += dp1[i];

        if( i != 0 ) dp1[i] += dp1[i-1];
    }
    cout << dp1.back().val() << endl;
    
    return 0;
}