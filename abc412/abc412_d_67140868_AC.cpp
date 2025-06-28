/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc412/submissions/67140868
 * Submitted at: 2025-06-28 21:30:15
 * Problem URL: https://atcoder.jp/contests/abc412/tasks/abc412_d
 * Result: AC
 * Execution Time: 18 ms
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
  vector<vector<bool>> g(n, vector<bool>(n, false));
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    g[a][b] = true;
    g[b][a] = true;
  }
  vector<ll> perm(n);
  iota(perm.begin(), perm.end(), 0);
  ll ans = INF;
  vector<vector<bool>> want;
  do {
    want.assign(n, vector<bool>(n, false));
    ll cand = 0;
    rep(i, n) {
      want[perm[i]][perm[(i + 1) % n]] = true;
      want[perm[(i + 1) % n]][perm[i]] = true;
    }
    rep(i, n) for(ll j = i + 1; j < n; j++) {
      if(g[i][j] != want[i][j]) {
        cand++;
      }
    }
    ans = min(ans, cand);
  } while(next_permutation(perm.begin(), perm.end()));

  if(n >= 6) {
    want.assign(n, vector<bool>(n, false));
    rep(i, (1LL << n)) {
      vector<ll> g1, g2;
      rep(j, n) {
        if(i & (1LL << j)) g1.emplace_back(j);
        else g2.emplace_back(j);
      }
      if(g1.size() < 3 || g2.size() < 3) continue;

      sort(g1.begin(), g1.end());
      sort(g2.begin(), g2.end());

      do {
        rep(j, g1.size()) {
          want[g1[j]][g1[(j + 1) % g1.size()]] = true;
          want[g1[(j + 1) % g1.size()]][g1[j]] = true;
        }
        do {
          rep(j, g2.size()) {
            want[g2[j]][g2[(j + 1) % g2.size()]] = true;
            want[g2[(j + 1) % g2.size()]][g2[j]] = true;
          }

          ll cand = 0;
          rep(j, n) for(ll k = j + 1; k < n; k++) {
            if(g[j][k] != want[j][k]) {
              cand++;
            }
          }
          ans = min(ans, cand);

          rep(j, g2.size()) {
            want[g2[j]][g2[(j + 1) % g2.size()]] = false;
            want[g2[(j + 1) % g2.size()]][g2[j]] = false;
          }
        } while(next_permutation(g2.begin(), g2.end()));

        rep(j, g1.size()) {
          want[g1[j]][g1[(j + 1) % g1.size()]] = false;
          want[g1[(j + 1) % g1.size()]][g1[j]] = false;
        }
      } while(next_permutation(g1.begin(), g1.end()));
    }
  }

  cout << ans << endl;

  return 0;
}