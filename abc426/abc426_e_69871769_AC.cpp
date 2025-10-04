/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc426/submissions/69871769
 * Submitted at: 2025-10-04 22:24:10
 * Problem URL: https://atcoder.jp/contests/abc426/tasks/abc426_e
 * Result: AC
 * Execution Time: 910 ms
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

  cout << setprecision(15) << fixed;

  ll t;
  cin >> t;
  using ld = long double;
  using P  = pair<ld, ld>;

  while(t--) {
    ld tsx, tsy, tgx, tgy, asx, asy, agx, agy;
    cin >> tsx >> tsy >> tgx >> tgy >> asx >> asy >> agx >> agy;
    ld stop_t = sqrt((tgx - tsx) * (tgx - tsx) + (tgy - tsy) * (tgy - tsy));
    ld stop_a = sqrt((agx - asx) * (agx - asx) + (agy - asy) * (agy - asy));
    P delta_t = P((tgx - tsx) / stop_t, (tgy - tsy) / stop_t);
    P delta_a = P((agx - asx) / stop_a, (agy - asy) / stop_a);

    ld ans = INF;

    // 三分探索 (実数値ver)
    ld left = 0, right = min(stop_t, stop_a);
    while(right - left > 0.000000001) {
      ld c1    = (left + left + right) / 3;
      ld c2    = (left + right + right) / 3;
      P pt1    = P(tsx + delta_t.first * min(c1, stop_t), tsy + delta_t.second * min(c1, stop_t));
      P pa1    = P(asx + delta_a.first * min(c1, stop_a), asy + delta_a.second * min(c1, stop_a));
      ld dist1 = (pt1.first - pa1.first) * (pt1.first - pa1.first) + (pt1.second - pa1.second) * (pt1.second - pa1.second);
      P pt2    = P(tsx + delta_t.first * min(c2, stop_t), tsy + delta_t.second * min(c2, stop_t));
      P pa2    = P(asx + delta_a.first * min(c2, stop_a), asy + delta_a.second * min(c2, stop_a));
      ld dist2 = (pt2.first - pa2.first) * (pt2.first - pa2.first) + (pt2.second - pa2.second) * (pt2.second - pa2.second);
      if(dist1 <= dist2) right = c2;
      else left = c1;
    }
    P pt    = P(tsx + delta_t.first * min(left, stop_t), tsy + delta_t.second * min(left, stop_t));
    P pa    = P(asx + delta_a.first * min(left, stop_a), asy + delta_a.second * min(left, stop_a));
    ld cand = sqrt((pt.first - pa.first) * (pt.first - pa.first) + (pt.second - pa.second) * (pt.second - pa.second));
    ans     = min(ans, cand);

    left = min(stop_t, stop_a), right = max(stop_t, stop_a);
    while(right - left > 0.000000001) {
      ld c1    = (left + left + right) / 3;
      ld c2    = (left + right + right) / 3;
      P pt1    = P(tsx + delta_t.first * min(c1, stop_t), tsy + delta_t.second * min(c1, stop_t));
      P pa1    = P(asx + delta_a.first * min(c1, stop_a), asy + delta_a.second * min(c1, stop_a));
      ld dist1 = (pt1.first - pa1.first) * (pt1.first - pa1.first) + (pt1.second - pa1.second) * (pt1.second - pa1.second);
      P pt2    = P(tsx + delta_t.first * min(c2, stop_t), tsy + delta_t.second * min(c2, stop_t));
      P pa2    = P(asx + delta_a.first * min(c2, stop_a), asy + delta_a.second * min(c2, stop_a));
      ld dist2 = (pt2.first - pa2.first) * (pt2.first - pa2.first) + (pt2.second - pa2.second) * (pt2.second - pa2.second);
      if(dist1 <= dist2) right = c2;
      else left = c1;
    }
    pt   = P(tsx + delta_t.first * min(left, stop_t), tsy + delta_t.second * min(left, stop_t));
    pa   = P(asx + delta_a.first * min(left, stop_a), asy + delta_a.second * min(left, stop_a));
    cand = sqrt((pt.first - pa.first) * (pt.first - pa.first) + (pt.second - pa.second) * (pt.second - pa.second));
    ans  = min(ans, cand);

    cout << ans << "\n";
  }

  return 0;
}