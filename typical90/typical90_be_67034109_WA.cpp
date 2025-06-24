/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67034109
 * Submitted at: 2025-06-24 11:57:28
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_be
 * Result: WA
 * Execution Time: 13 ms
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
  vector<ll> s(m, 0);
  rep(i, m) cin >> s[i];

  vector<bool> used(n, false);
  rep(idx, m) {
    ll pivot = -1;
    rep(i, n) {
      if(used[i] || a[i][idx] == 0) continue;
      pivot = i;
      break;
    }
    if(pivot == -1 && s[idx] == 1) {
      cout << 0 << endl;
      return 0;
    }

    if(pivot != -1) {
      used[pivot] = true;
      rep(i, m) s[i] ^= a[pivot][i];
      rep(i, n) {
        if(used[i] || i == pivot || a[i][idx] == 0) continue;
        rep(j, m) a[i][j] ^= a[pivot][j];
      }
    }
    // rep(i, n) {
    //   rep(j, m) cerr << a[i][j] << " ";
    //   cerr << endl;
    // }
    // cerr << endl;
  }
  ll all_zero = 0;
  rep(i, n) {
    bool zero = true;
    rep(j, m) zero &= (a[i][j] == 0);
    if(zero) all_zero++;
  }
  cout << mint(2).pow(all_zero).val() << endl;

  return 0;
}
