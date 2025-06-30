/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67201789
 * Submitted at: 2025-06-30 19:43:36
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cj
 * Result: WA
 * Execution Time: 35 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
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

  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  dsu uf(n);
  rep(i, q) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    uf.merge(x, y);
  }
  vector<vector<int>> groups = uf.groups();
  ll size                    = groups.size();

  ll max_sum = 8888;
  vector<vector<bool>> dp(size + 1, vector<bool>(max_sum + 1, false));
  vector<vector<vector<P>>> prev(size + 1, vector<vector<P>>(max_sum + 1, vector<P>{}));
  dp[0][0] = true;
  rep(i, size) rep(j, max_sum + 1) {
    if(!dp[i][j]) continue;
    dp[i + 1][j] = true;
    prev[i + 1][j].emplace_back(P(j, -1));

    for(auto &x: groups[i]) {
      if(j + a[x] > max_sum) continue;
      dp[i + 1][j + a[x]] = true;
      prev[i + 1][j + a[x]].emplace_back(P(j, x));
    }
  }

  vector<ll> ans1, ans2, cand1, cand2;
  for(ll sum = 1; sum <= max_sum; sum++) {
    if(!dp[size][sum]) continue;
    ll now_i = size, now_j = sum;
    cand1.clear();
    cand2.clear();

    while(now_i > 0) {
      auto [prev_j, x] = prev[now_i][now_j][0];
      if(x != -1) {
        cand1.emplace_back(x);
        now_j = prev_j;
      }
      now_i--;
    }
    now_i = size, now_j = sum;
    while(now_i > 0) {
      auto [prev_j, x] = prev[now_i][now_j].back();
      if(x != -1) {
        cand2.emplace_back(x);
        now_j = prev_j;
      }
      now_i--;
    }
    if(cand1 != cand2) {
      swap(ans1, cand1);
      swap(ans2, cand2);
      break;
    }
  }
  sort(ans1.begin(), ans1.end());
  sort(ans2.begin(), ans2.end());
  cout << ans1.size() << endl;
  rep(i, ans1.size()) cout << ans1[i] + 1 << " ";
  cout << endl;
  cout << ans2.size() << endl;
  rep(i, ans2.size()) cout << ans2[i] + 1 << " ";
  cout << endl;

  return 0;
}
