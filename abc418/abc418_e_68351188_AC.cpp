/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc418/submissions/68351188
 * Submitted at: 2025-08-09 21:58:53
 * Problem URL: https://atcoder.jp/contests/abc418/tasks/abc418_e
 * Result: AC
 * Execution Time: 1428 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

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

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<P> p(n);
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    p[i] = {x, y};
  }

  vector<P> dirs;
  rep(i, n) for(ll j = i + 1; j < n; j++) {
    Line L(p[i], p[j]);
    dirs.emplace_back(L.a, L.b);
  }
  sort(dirs.begin(), dirs.end());

  ll m   = (ll) dirs.size();
  ll sum = 0;
  for(ll l = 0; l < m;) {
    ll r = l + 1;
    while(r < m && dirs[r] == dirs[l]) r++;
    sum += (r - l) * (r - l - 1) / 2;
    l = r;
  }

  ll total = 0;
  vector<P> tmp;
  rep(i, n) {
    tmp.clear();
    rep(j, n) if(j != i) {
      Line L(p[i], p[j]);
      tmp.emplace_back(L.a, L.b);
    }
    sort(tmp.begin(), tmp.end());
    for(ll l = 0; l < tmp.size();) {
      ll r = l + 1;
      while(r < tmp.size() && tmp[r] == tmp[l]) r++;
      total += (r - l) * (r - l - 1) / 2;
      l = r;
    }
  }

  ll pairs = sum - total;
  vector<P> mids;
  rep(i, n) for(ll j = i + 1; j < n; j++) {
    auto &&[x1, y1] = p[i];
    auto &&[x2, y2] = p[j];
    mids.emplace_back(x1 + x2, y1 + y2);
  }
  sort(mids.begin(), mids.end());

  ll heiko_shihen = 0;
  for(ll l = 0; l < mids.size();) {
    ll r = l + 1;
    while(r < mids.size() && mids[r] == mids[l]) r++;
    heiko_shihen += (r - l) * (r - l - 1) / 2;
    l = r;
  }

  ll ans = pairs - heiko_shihen;
  cout << ans << '\n';

  return 0;
}
