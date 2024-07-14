/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55608424
 * Submitted at: 2024-07-14 19:42:52
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_g
 * Result: TLE
 * Execution Time: 3316 ms
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
    if(b != 0)
      return euclid(b, a % b);
    else
      return a;
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

  string s;
  cin >> s;
  ll q;
  cin >> q;
  // 長さの種類は高々 √N 通り？
  // ⇒ 長さ毎に行うと実は愚直が間に合う？

  RollingHash rh(s);
  vector<RollingHash> rh2(q);

  vector<ll> exist(s.size() + 1, 0);
  vector<string> t(q);
  map<ll, ll> ans;
  rep(i, q) {
    cin >> t[i];
    rh2[i] = RollingHash(t[i]);
    exist[t[i].size()]++;
    ans[rh2[i].get(0, t[i].size())] = 0;
  }
  for(int i = 1; i <= s.size(); i++) {
    if(exist[i] == 0) continue;
    rep(j, s.size() - i + 1) {
      if(!ans.count(rh.get(j, j + i))) continue;
      ans[rh.get(j, j + i)]++;
    }
  }
  rep(i, q) cout << ans[rh2[i].get(0, t[i].size())] << endl;

  return 0;
}