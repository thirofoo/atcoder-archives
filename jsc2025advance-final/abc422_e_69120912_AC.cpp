/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/jsc2025advance-final/submissions/69120912
 * Submitted at: 2025-09-07 14:00:32
 * Problem URL: https://atcoder.jp/contests/jsc2025advance-final/tasks/abc422_e
 * Result: AC
 * Execution Time: 1561 ms
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

using P = pair<ll, ll>;

struct Line {
  // type 1: y = ax + b (勾配 a, 切片 b)
  // type 2: ax + by + c = 0 (2頂点 p1, p2 を通る直線)
  ll a, b, c, type;
  Line(const ll a, const ll b): a(a), b(b), c(0), type(1) {}
  Line(const P &p1, const P &p2): type(2) {
    if(p1 == p2) cerr << "Warn: Same Vertex (p1,p2)\n";
    auto &&[x1, y1] = p1;
    auto &&[x2, y2] = p2;
    ll dx = x1 - x2, dy = y1 - y2;
    a = -dy, b = dx, c = dy * x1 - dx * y1;

    // gcd(a,b,c) = 1 & a > 0 で管理 ※ a == 0 の時は b > 0 で管理
    if(a < 0 || (a == 0 && b < 0)) a *= -1, b *= -1, c *= -1;
    ll g = gcd(abs(a), gcd(abs(b), abs(c)));
    a /= g, b /= g, c /= g;
  }
  inline bool isOnLine(const P &p) {
    auto &&[x, y] = p;
    bool res      = false;
    res |= (type == 1 && y == a * x + b);
    res |= (type == 2 && a * x + b * y + c == 0);
    return res;
  }
  // 演算子 overload (sort用)
  constexpr bool operator<(const Line &l) const {
    return tuple(a, b, c) < tuple(l.a, l.b, l.c);
  }
  constexpr bool operator>(const Line &l) const {
    return tuple(a, b, c) > tuple(l.a, l.b, l.c);
  }
  constexpr bool operator==(const Line &l) const {
    return a == l.a && b == l.b && c == l.c;
  }
};

namespace utility {
  struct timer {
    chrono::system_clock::time_point start;
    // 開始時間を記録
    void CodeStart() {
      start = chrono::system_clock::now();
    }
    // 経過時間 (ms) を返す
    double elapsed() const {
      using namespace std::chrono;
      return (double) duration_cast<milliseconds>(system_clock::now() - start).count();
    }
  } mytm;
} // namespace utility

inline unsigned int rand_int() {
  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
  unsigned int tt = (tx ^ (tx << 11));
  tx = ty, ty = tz, tz = tw;
  return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  utility::mytm.CodeStart();

  while(utility::mytm.elapsed() < 1500) {
    ll idx1 = rand_int() % n, idx2 = rand_int() % n;
    if(idx1 == idx2) continue;
    Line line({x[idx1], y[idx1]}, {x[idx2], y[idx2]});
    ll cnt = 0;
    rep(i, n) if(line.isOnLine({x[i], y[i]})) cnt++;
    if(cnt >= (n + 1) / 2) {
      cout << "Yes\n";
      cout << line.a << " " << line.b << " " << line.c << "\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}