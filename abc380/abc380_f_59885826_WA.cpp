/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc380/submissions/59885826
 * Submitted at: 2024-11-17 01:11:00
 * Problem URL: https://atcoder.jp/contests/abc380/tasks/abc380_f
 * Result: WA
 * Execution Time: 25 ms
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

  // 適当に dp する
  ll n, m, l, total;
  cin >> n >> m >> l;
  total = n + m + l;
  vector<ll> card(total);
  ll s_aoki = 0, s_takahashi = 0, s_p = 0;
  rep(i, total) {
    cin >> card[i];
    if(i < n) s_takahashi |= (1LL << i);
    else if(i < n + m) s_aoki |= (1LL << i);
    else s_p |= (1LL << i);
  }

  using T = tuple<ll, ll, ll, ll>;
  map<T, bool> dp;

  auto dfs = [&](auto self, ll aoki, ll takahashi, ll p, ll turn) -> bool {
    if(dp.count({aoki, takahashi, p, turn})) return dp[{aoki, takahashi, p, turn}];
    // turn % 2 == 0 ? Takahashi のターン : Aoki のターン
    if(turn % 2 == 0) {
      rep(i, total) {
        if(!((1LL << i) & takahashi)) continue;
        ll ntakahashi = takahashi ^ (1LL << i);
        ll np         = p ^ (1LL << i);
        if(!self(self, aoki, ntakahashi, np, turn + 1)) {
          return dp[{aoki, takahashi, p, turn}] = true;
        }
        rep(j, total) {
          if(!((1LL << j) & p) || card[i] <= card[j]) continue;
          if(!self(self, aoki, ntakahashi ^ (1LL << j), np ^ (1LL << j), turn + 1)) {
            return dp[{aoki, takahashi, p, turn}] = true;
          }
        }
      }
    } else {
      rep(i, total) {
        if(!(1LL << i) & aoki) continue;
        ll naoki = aoki ^ (1LL << i);
        ll np    = p ^ (1LL << i);
        if(!self(self, naoki, takahashi, np, turn + 1)) {
          return dp[{aoki, takahashi, p, turn}] = true;
        }
        rep(j, total) {
          if(!((1LL << j) & p) || card[i] <= card[j]) continue;
          if(!self(self, naoki ^ (1LL << j), takahashi, np ^ (1LL << j), turn + 1)) {
            return dp[{aoki, takahashi, p, turn}] = true;
          }
        }
      }
    }
    return dp[{aoki, takahashi, p, turn}] = false;
  };
  cout << (dfs(dfs, s_aoki, s_takahashi, s_p, 0) ? "Takahashi" : "Aoki") << endl;

  return 0;
}