/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc314/submissions/45702255
 * Submitted at: 2023-09-18 16:56:48
 * Problem URL: https://atcoder.jp/contests/abc314/tasks/abc314_e
 * Result: WA
 * Execution Time: 2 ms
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
    cout << setprecision(10) << fixed;
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> roulette;
    vector<ll> c(n);
    // point : 出目0は、確立漸化式を組んで存在を抹消する
    // ※ ルーレットに0が含まれると計算量 O(∞) になる為
    // 確立漸化式を組むと金額の期待値は p / (p-n_zero) * C になる為それを利用
    rep(i,n) {
        ll p; cin >> c[i] >> p;
        vector<ll> s;
        double num_zero = 0;
        rep(j,p) {
            ll ts; cin >> ts;
            if( ts == 0 ) num_zero++;
            else s.emplace_back(ts);
        }
        c[i] = (double)p / ((double)p - num_zero) * c[i];
        roulette.emplace_back(s);
    }

    // dp[i] : iポイント獲得した時の金額の期待値
    vector<double> dp(m+1, 1e9);
    dp[0] = 0.0;
    for(ll i=1;i<=m;i++) {
        rep(j,n) {
            double cand = 0.0;
            for(auto r:roulette[j]) cand += dp[max(0ll,i-r)];
            cand /= roulette[j].size();
            cand += c[j];
            dp[i] = min(dp[i], cand);
        }   
    }
    cout << dp[m] << endl;
    
    return 0;
}