/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc369/submissions/61052235
 * Submitted at: 2024-12-24 15:04:18
 * Problem URL: https://atcoder.jp/contests/abc369/tasks/abc369_e
 * Result: AC
 * Execution Time: 172 ms
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

  using P = pair<ll, ll>;

  ll n, m;
  cin >> n >> m;
  vector warshall(n, vector<ll>(n, INF));
  vector<ll> from(m, -1), to(m, -1), time(m, -1);
  rep(i, m) {
    cin >> from[i] >> to[i] >> time[i];
    from[i]--, to[i]--;
    warshall[from[i]][to[i]] = min(warshall[from[i]][to[i]], time[i]);
    warshall[to[i]][from[i]] = min(warshall[to[i]][from[i]], time[i]);
  }
  rep(i, n) warshall[i][i]                     = 0;
  rep(k, n) rep(i, n) rep(j, n) warshall[i][j] = min(warshall[i][j], warshall[i][k] + warshall[k][j]);
  // rep(i, n) rep(j, n) cerr << warshall[i][j] << " \n"[j == n - 1];

  ll q;
  cin >> q;
  while(q--) {
    ll k;
    cin >> k;
    vector<ll> b(k);
    rep(i, k) cin >> b[i], b[i]--;
    vector<ll> perm(k);
    iota(perm.begin(), perm.end(), 0);
    ll ans = INF;
    do {
      rep(j, (1LL << k)) {
        ll start = 0, cand = 0;
        rep(i, k) {
          if(j & (1LL << i)) {
            cand += warshall[start][from[b[perm[i]]]];
            cand += time[b[perm[i]]];
            start = to[b[perm[i]]];
          } else {
            cand += warshall[start][to[b[perm[i]]]];
            cand += time[b[perm[i]]];
            start = from[b[perm[i]]];
          }
        }
        // cerr << "cand: " << cand << '\n';
        cand += warshall[start][n - 1];
        ans = min(ans, cand);
      }
    } while(next_permutation(perm.begin(), perm.end()));
    cout << ans << '\n';
  }

  return 0;
}