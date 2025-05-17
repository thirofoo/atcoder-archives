/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc406/submissions/65889964
 * Submitted at: 2025-05-17 21:36:28
 * Problem URL: https://atcoder.jp/contests/abc406/tasks/abc406_c
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

  ll n;
  cin >> n;
  vector<ll> p(n), idx1, idx2;
  rep(i, n) cin >> p[i];
  vector<ll> idxs;
  idxs.emplace_back(0);
  bool flag = false;
  rep(i, n - 2) {
    if((p[i] > p[i + 1] && p[i + 1] < p[i + 2]) || (p[i] < p[i + 1] && p[i + 1] > p[i + 2])) {
      if(idxs.size() == 1) flag = (p[i] < p[i + 1] && p[i + 1] > p[i + 2]);
      idxs.emplace_back(i + 1);
    }
  }
  idxs.emplace_back(n - 1);
  ll ans  = 0;
  bool ok = false;
  // rep(i, idxs.size()) cerr << idxs[i] << " ";
  // cerr << endl;
  // cerr << "flag: " << flag << endl;
  for(ll i = (flag ? 1 : 2); i < idxs.size() - 2; i += 2) {
    // cerr << idxs[i] - idxs[i - 1] << " " << idxs[i + 2] - idxs[i + 1] << endl;
    ans += (idxs[i] - idxs[i - 1]) * (idxs[i + 2] - idxs[i + 1]);
    ok = true;
  }
  cout << (ok ? ans : 0) << endl;

  return 0;
}