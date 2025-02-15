/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc393/submissions/62786886
 * Submitted at: 2025-02-15 21:32:08
 * Problem URL: https://atcoder.jp/contests/abc393/tasks/abc393_e
 * Result: AC
 * Execution Time: 1361 ms
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

  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), cnt(1000001, 0), div_cnt(1000001, 0);
  rep(i, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  // 調和級数になりそう？
  for(ll i = 1000000; i >= 1; i--) {
    ll sum = 0;
    for(ll j = i; j <= 1000000; j += i) div_cnt[i] += cnt[j];
  }
  // rep(i, 20) cerr << div_cnt[i] << " ";
  // cerr << endl;
  vector<ll> ans(1000001, 0);
  for(ll i = 1; i <= 1000000; i++) {
    if(div_cnt[i] < k) continue;
    for(ll j = i; j <= 1000000; j += i) ans[j] = max(ans[j], i);
  }
  // rep(i, 20) cerr << ans[i] << " ";
  // cerr << endl;
  rep(i, n) cout << ans[a[i]] << endl;

  return 0;
}