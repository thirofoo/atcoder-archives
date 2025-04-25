/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc331/submissions/65188641
 * Submitted at: 2025-04-25 18:32:25
 * Problem URL: https://atcoder.jp/contests/abc331/tasks/abc331_f
 * Result: AC
 * Execution Time: 479 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

class RollingHash {
  using ull = unsigned long long;

  public:
  static const ull Mod = (1LL << 61) - 1;
  static ull base;
  static vector<ull> powr;

  RollingHash() {
    if(base == 0) {
      random_device rnd;
      mt19937 mt(rnd());
      uniform_int_distribution<ull> rand(1, INT_MAX);
      while(true) {
        ull k = rand(mt);
        base  = modPow(37, k);
        if(euclid(Mod - 1, k) == 1 && base > 1e9) break;
      }
      if(powr.empty()) powr.assign(1, 1);
    }
  }

  explicit RollingHash(const string &s) {
    if(base == 0) {
      random_device rnd;
      mt19937 mt(rnd());
      uniform_int_distribution<ull> rand(1, INT_MAX);
      while(true) {
        ull k = rand(mt);
        base  = modPow(37, k);
        if(euclid(Mod - 1, k) == 1 && base > 1e9) break;
      }
    }
    if(powr.empty()) powr.assign(1, 1);
    int size = s.size();
    hash.assign(size + 1, 0);
    for(int i = 0; i < size; i++) {
      hash[i + 1] = mulMod(hash[i], base) + s[i];
      hash[i + 1] = getMod(hash[i + 1]);
    }
  }

  ull get(int l, int r) {
    ull res = hash[r] - mulMod(hash[l], RollingHash::getPow(r - l));
    return getMod(res + Positivizer);
  }

  static const ull Positivizer = Mod * 7;
  vector<ull> hash;

  static ull getPow(int n) {
    while(powr.size() <= n) {
      powr.emplace_back(RollingHash::mulMod(powr.back(), base));
    }
    return powr[n];
  }

  static ull mulMod(ull x, ull y) {
    __int128_t t = (__int128_t) x * y;
    t            = (t >> 61) + (t & Mod);
    if(t >= Mod) t -= Mod;
    return (ull) t;
  }

  static ull getMod(ull val) {
    val = (val >> 61) + (val & Mod);
    if(val >= Mod) val -= Mod;
    return (ull) val;
  }

  static ull euclid(ull a, ull b) {
    return b ? euclid(b, a % b) : a;
  }

  static ull modPow(ull a, ull b) {
    ull res = 1;
    for(; b; a = RollingHash::getMod(a * a), b >>= 1) {
      if(b & 1) res = RollingHash::getMod(res * a);
    }
    return res;
  }
};

ull RollingHash::base = 0;
vector<ull> RollingHash::powr;

using S = struct {
  ll hash;
  int len;
};

S op(S l, S r) {
  S res;
  res.len  = l.len + r.len;
  res.hash = RollingHash::getMod(r.hash + RollingHash::mulMod(l.hash, RollingHash::getPow(r.len)));
  return res;
}

S e() {
  return {0, 0};
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  RollingHash rh(s);
  segtree<S, op, e> seg1(n), seg2(n);
  rep(i, n) {
    seg1.set(i, {s[i], 1LL});
    seg2.set(i, {s[n - i - 1], 1LL});
  }

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll x;
      char c;
      cin >> x >> c;
      seg1.set(x - 1, {c, 1LL});
      seg2.set(n - x, {c, 1LL});
    } else {
      ll l, r;
      cin >> l >> r;
      cout << (seg1.prod(l - 1, r).hash == seg2.prod(n - r, n - l + 1).hash ? "Yes" : "No") << '\n';
    }
  }

  return 0;
}
