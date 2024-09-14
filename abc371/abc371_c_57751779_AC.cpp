/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc371/submissions/57751779
 * Submitted at: 2024-09-14 21:16:34
 * Problem URL: https://atcoder.jp/contests/abc371/tasks/abc371_c
 * Result: AC
 * Execution Time: 9 ms
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

  ll n;
  cin >> n;
  vector<vector<bool>> g1(n, vector<bool>(n, false)), g2(n, vector<bool>(n, false));
  ll m1;
  cin >> m1;
  rep(i, m1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    g1[a][b] = true;
    g1[b][a] = true;
  }
  ll m2;
  cin >> m2;
  rep(i, m2) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    g2[a][b] = true;
    g2[b][a] = true;
  }
  vector<vector<ll>> a(n, vector<ll>(n, INF));
  rep(i, n) for(ll j = 1 + i; j < n; j++) {
    cin >> a[i][j];
    a[j][i] = a[i][j];
  }

  vector<ll> perm(n, 0);
  iota(perm.begin(), perm.end(), 0);
  ll ans = INF;
  do {
    ll cand = 0;
    rep(i, n) for(ll j = 1 + i; j < n; j++) {
      if(g1[i][j] != g2[perm[i]][perm[j]]) cand += a[perm[i]][perm[j]];
    }
    ans = min(ans, cand);
  } while(next_permutation(perm.begin(), perm.end()));
  cout << ans << '\n';

  return 0;
}