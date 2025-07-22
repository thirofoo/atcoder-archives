/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc377/submissions/67821294
 * Submitted at: 2025-07-22 11:40:12
 * Problem URL: https://atcoder.jp/contests/abc377/tasks/abc377_g
 * Result: AC
 * Execution Time: 114 ms
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

class RollingHash {
  using ull = unsigned long long;

  public:
  static const ull Mod = (1LL << 61) - 1;
  static ull base; // 基数

  RollingHash() {}
  explicit RollingHash(const string &s) {
    if(base == 0) {
      // base を 2^61-1の原始根 & 1e9以上 で初期化
      random_device rnd;
      mt19937 mt(rnd());
      uniform_int_distribution<ull> rand(1, INT_MAX);
      while(true) {
        ull k = rand(mt);
        base  = modPow(37, k);
        if(euclid(Mod - 1, k) == 1 && base > 1e9) break;
      }
    }
    powr.assign(1, 1);
    int size = s.size();
    hash.assign(size + 1, 0);
    // 左端からの hash 前計算
    for(int i = 0; i < size; i++) {
      hash[i + 1] = mulMod(hash[i], base) + s[i];
      hash[i + 1] = getMod(hash[i + 1]);
    }
  }

  ull get(int l, int r) {
    ull res = hash[r] - mulMod(hash[l], getPow(r - l));
    return getMod(res + Positivizer);
  }

  private:
  static const ull Positivizer = Mod * 7;
  vector<ull> hash; // hash のキャッシュ
  vector<ull> powr; // 基数の累乗

  ull getPow(int n) {
    while(powr.size() <= n) {
      // 次の基数の累乗を求める
      powr.emplace_back(mulMod(powr.back(), base));
    }
    return powr[n];
  }

  ull mulMod(ull x, ull y) {
    // Fermat の小定理 & 2進数のmod を利用
    __int128_t t = (__int128_t) x * y;
    t            = (t >> 61) + (t & Mod);
    if(t >= Mod) t -= Mod;
    return (ull) t;
  }

  ull getMod(ull val) {
    val = (val >> 61) + (val & Mod);
    if(val >= Mod) val -= Mod;
    return (ull) val;
  }

  ull euclid(ull a, ull b) {
    if(b != 0) return euclid(b, a % b);
    else return a;
  }

  ull modPow(ull a, ull b) {
    ull res = 1;
    for(; b; a = getMod(a * a), b >>= 1) {
      if(b & 1) res = getMod(res * a);
    }
    return res;
  }
};

// 基数の初期化（複数の Hash で比較するために基底は共有）
ull RollingHash::base = 0;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<string> s(n);

  using P = pair<ll, ll>;
  multiset<P> ms;
  vector<vector<ull>> prefixs(n);

  rep(i, n) {
    cin >> s[i];
    RollingHash rh(s[i]);
    rep(j, s[i].size()) prefixs[i].emplace_back(rh.get(0, s[i].size() - j));
  }

  rep(i, n) {
    ll ans = s[i].size();
    rep(j, s[i].size()) {
      auto it = ms.lower_bound({prefixs[i][j], -INF});
      if(it == ms.end() || (*it).first != prefixs[i][j]) continue;
      ans = min(ans, j + (*it).second);
    }
    cout << ans << '\n';

    rep(j, s[i].size()) ms.insert({prefixs[i][j], j});
  }

  return 0;
}