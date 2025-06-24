/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67033727
 * Submitted at: 2025-06-24 11:31:31
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_be
 * Result: WA
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m, 0));
  rep(i, n) {
    ll t;
    cin >> t;
    rep(j, t) {
      ll x;
      cin >> x;
      a[i][x - 1] = 1;
    }
  }
  // 解説 AC : 有限体 F_2 上の掃き出し法で解ける
  // ★ 掃き出し法後のベクトルも元の操作と一対一対応してるので、掃き出し法をしても OK
  vector<vector<ll>> next_a;
  vector<bool> used(n, false);
  ll idx = 0;
  while(idx < m) {
    ll pivot = -1;
    for(ll i = 0; i < n; i++) {
      if(used[i]) continue;
      if(a[i][idx] == 1) {
        pivot = i;
        break;
      }
    }
    if(pivot == -1) {
      idx++;
      continue;
    }
    next_a.emplace_back(a[pivot]);
    rep(i, n) {
      if(used[i]) continue;
      if(i != pivot && a[i][idx] == 1) {
        rep(j, m) a[i][j] ^= a[pivot][j];
      }
    }
    used[pivot] = true;
    idx++;
  }

  vector<ll> s(m, 0);
  rep(i, m) cin >> s[i];
  idx = 0;
  rep(i, m) {
    if(s[i] == 0) continue;
    while(idx < next_a.size() && next_a[idx][i] == 0) idx++;
    if(idx == next_a.size()) {
      cout << 0 << endl;
      return 0;
    }
    rep(j, m) s[j] ^= next_a[idx][j];
    idx++;
  }
  cout << (idx >= n ? mint(1) : mint(2).pow(n - idx - 1)).val() << endl;

  return 0;
}
