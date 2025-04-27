/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65298622
 * Submitted at: 2025-04-28 02:50:27
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_e
 * Result: AC
 * Execution Time: 271 ms
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

  ll q;
  cin >> q;
  unordered_set<ull> prefix_hash;
  unordered_map<ull, vector<ll>> hash_idx;

  ll total_str = 0;
  set<ll> erased_idx;

  while(q--) {
    ll t;
    string s;
    cin >> t >> s;
    RollingHash rh(s);
    if(t == 1) {
      prefix_hash.insert(rh.get(0, s.size()));
      for(auto &idx: hash_idx[rh.get(0, s.size())]) erased_idx.insert(idx);
      hash_idx[rh.get(0, s.size())].clear();
    } else {
      bool ok = true;
      rep(i, s.size()) {
        ok &= !prefix_hash.count(rh.get(0, i + 1));
        if(!ok) break;
      }
      if(ok) {
        total_str++;
        rep(i, s.size()) hash_idx[rh.get(0, i + 1)].emplace_back(q);
      }
    }
    cout << total_str - erased_idx.size() << endl;
  }

  return 0;
}
