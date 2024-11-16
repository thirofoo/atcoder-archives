/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc380/submissions/59877036
 * Submitted at: 2024-11-16 22:39:42
 * Problem URL: https://atcoder.jp/contests/abc380/tasks/abc380_f
 * Result: WA
 * Execution Time: 12 ms
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

  // 適当に Grundy する
  ll n, m, l, total;
  cin >> n >> m >> l;
  total = n + m + l;
  vector<ll> card(total);
  ll s_aoki = 0, s_takahashi = 0, s_p = 0;
  rep(i, total) {
    cin >> card[i];
    if(i < n) s_aoki |= (1LL << i);
    else if(i < n + m) s_takahashi |= (1LL << i);
    else s_p |= (1LL << i);
  }

  using T = tuple<ll, ll, ll>;
  map<T, ll> grundy;

  auto dfs = [&](auto self, ll aoki, ll takahashi, ll p, ll turn) -> ll {
    if(grundy.count({aoki, takahashi, p})) return grundy[{aoki, takahashi, p}];
    // turn % 2 == 0 : Takahashi のターン
    // turn % 2 == 1 : Aoki のターン
    ll res    = 0;
    bool flag = false;
    if(turn % 2 == 0) {
      // 捨てるカード全探索
      rep(i, total) {
        if(!((takahashi >> i) & 1)) continue;
        ll ntakahashi = takahashi ^ (1LL << i);
        rep(j, total) {
          if(((p >> j) & 1) && (card[i] > card[j])) {
            res ^= self(self, aoki, ntakahashi ^ (1LL << j), p ^ (1LL << j), turn + 1);
            flag = true;
          } else if((p >> j) & 1) {
            res ^= self(self, aoki, ntakahashi, p, turn + 1);
            flag = true;
          }
        }
      }
    } else {
      // 捨てるカード全探索
      rep(i, total) {
        if(!((aoki >> i) & 1)) continue;
        ll naoki = aoki ^ (1LL << i);
        rep(j, total) {
          if(((p >> j) & 1) && (card[i] > card[j])) {
            res ^= self(self, naoki ^ (1LL << j), takahashi, p ^ (1LL << j), turn + 1);
            flag = true;
          } else if((p >> j) & 1) {
            res ^= self(self, naoki, takahashi, p, turn + 1);
            flag = true;
          }
        }
      }
    }
    if(!flag) res = (turn % 2);
    return grundy[{aoki, takahashi, p}] = res;
  };
  cout << (dfs(dfs, s_aoki, s_takahashi, s_p, 0) ? "Takahashi" : "Aoki") << endl;

  return 0;
}