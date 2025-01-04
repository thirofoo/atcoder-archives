/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc294/submissions/61359475
 * Submitted at: 2025-01-04 18:43:41
 * Problem URL: https://atcoder.jp/contests/abc294/tasks/abc294_f
 * Result: AC
 * Execution Time: 569 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ld = long double;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  // 解説 AC
  // 二分探索 + 平面操作っぽくやるまでは分かるが、その指標でミス
  // 誤 : (B + D) / (A + C) >= x [%] を条件式にする
  // 正 : 飲み物の砂糖 or 水の不足分の和が 0 以下か未満かを条件式にする
  // ※ 平面操作は

  cout << setprecision(10) << fixed << endl;
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n), b(n), c(m), d(m);
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, m) cin >> c[i] >> d[i];

  auto calc_rest = [&](ld sugar, ld water, ld rate) -> ld {
    return sugar - water * rate / (1.0 - rate);
  };

  ll time = 50;
  ld ok = 0.0, ng = 1.0;
  while(time--) {
    ld mid      = (ok + ng) / 2.0;
    ll pair_cnt = 0;
    vector<ld> rests;
    rep(i, m) rests.emplace_back(calc_rest(c[i], d[i], mid));
    sort(rests.begin(), rests.end());
    // rep(i, m) cerr << rests[i] << " ";
    // cerr << endl;
    rep(i, n) {
      ld rest = calc_rest(a[i], b[i], mid);
      pair_cnt += m - (lower_bound(rests.begin(), rests.end(), -rest) - rests.begin());
    }
    // cerr << "ok: " << ok << " ng: " << ng << " pair_cnt: " << pair_cnt << endl;
    if(pair_cnt >= k) ok = mid;
    else ng = mid;
  }
  cout << ok * 100.0 << endl;

  return 0;
}