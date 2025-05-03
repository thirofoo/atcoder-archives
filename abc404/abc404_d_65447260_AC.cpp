/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc404/submissions/65447260
 * Submitted at: 2025-05-03 21:33:58
 * Problem URL: https://atcoder.jp/contests/abc404/tasks/abc404_d
 * Result: AC
 * Execution Time: 63 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> c(n);
  vector<vector<bool>> visible(n, vector<bool>(m, false));
  rep(i, n) cin >> c[i];
  rep(i, m) {
    ll k;
    cin >> k;
    rep(j, k) {
      ll a;
      cin >> a;
      a--;
      visible[a][i] = true;
    }
  }

  ll ans = INF;
  rep(i, (1LL << n)) {
    vector<ll> idx;
    rep(j, n) if(i & (1LL << j)) idx.emplace_back(j);
    rep(j, (1LL << idx.size())) {
      ll cand = 0;
      vector<ll> cnt(m, 0);
      rep(k, idx.size()) {
        rep(l, m) if(visible[idx[k]][l]) cnt[l]++;
        cand += c[idx[k]];
        if(j & (1LL << k)) {
          rep(l, m) if(visible[idx[k]][l]) cnt[l]++;
          cand += c[idx[k]];
        }
      }
      bool ok = true;
      rep(k, m) ok &= (cnt[k] >= 2);
      if(ok) ans = min(ans, cand);
    }
  }
  cout << ans << endl;

  return 0;
}