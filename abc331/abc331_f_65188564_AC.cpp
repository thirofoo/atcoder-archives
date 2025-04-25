/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc331/submissions/65188564
 * Submitted at: 2025-04-25 18:28:09
 * Problem URL: https://atcoder.jp/contests/abc331/tasks/abc331_f
 * Result: AC
 * Execution Time: 605 ms
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
  static ull base;         // 基数 (static)
  static vector<ull> powr; // 基数の累乗 (static に変更)

  // コンストラクタは base の初期化を引き続き行いますが、powr の初期化方法を調整
  RollingHash() {
    if(base == 0) {
      // base を 2^61-1の原始根 & 1e9以上 で初期化
      random_device rnd;
      mt19937 mt(rnd());
      uniform_int_distribution<ull> rand(1, INT_MAX);
      while(true) {
        ull k = rand(mt);
        // modPow は static である必要あり
        base = modPow(37, k);
        // euclid は static である必要あり
        if(euclid(Mod - 1, k) == 1 && base > 1e9) break;
      }
      // base が初期化されたら powr も初期化 (初回のみ)
      if(powr.empty()) {
        powr.assign(1, 1);
      }
    }
    // インスタンスごとの hash ベクトルは必要
    // int size = s.size(); // コンストラクタ引数 s がないのでこの行は削除または適切に修正
    // hash.assign(size + 1, 0); // コンストラクタ引数 s がないのでこの行は削除または適切に修正
    // 左端からの hash 前計算 // コンストラクタ引数 s がないのでこのブロックは削除または適切に修正
  }

  // 文字列から RollingHash を構築するコンストラクタを追加
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
    // base が初期化されたら powr も初期化 (初回のみ)
    if(powr.empty()) {
      powr.assign(1, 1);
    }

    int size = s.size();
    hash.assign(size + 1, 0);
    // 左端からの hash 前計算
    for(int i = 0; i < size; i++) {
      hash[i + 1] = mulMod(hash[i], base) + s[i];
      hash[i + 1] = getMod(hash[i + 1]);
    }
  }

  // get 関数はおそらくインスタンスに対して呼び出すので非staticのままで良い
  ull get(int l, int r) {
    // getPow は static に変更したので RollingHash::getPow で呼び出す
    ull res = hash[r] - mulMod(hash[l], RollingHash::getPow(r - l));
    return getMod(res + Positivizer);
  }

  static const ull Positivizer = Mod * 7;
  vector<ull> hash; // hash のキャッシュ (インスタンスごと)

  // getPow を static に変更
  static ull getPow(int n) {
    // powr の遅延初期化はコンストラクタで行うようにしたのでここは不要かも
    // 必要ならここでも powr.empty() でチェックして初期化処理を呼び出す
    while(powr.size() <= n) {
      // 次の基数の累乗を求める
      // mulMod は static に変更したので RollingHash::mulMod で呼び出す
      powr.emplace_back(RollingHash::mulMod(powr.back(), base));
    }
    return powr[n];
  }

  // mulMod を static に変更
  static ull mulMod(ull x, ull y) {
    __int128_t t = (__int128_t) x * y;
    t            = (t >> 61) + (t & Mod);
    if(t >= Mod) t -= Mod;
    return (ull) t;
  }

  // getMod を static に変更
  static ull getMod(ull val) {
    val = (val >> 61) + (val & Mod);
    if(val >= Mod) val -= Mod;
    return (ull) val;
  }

  // euclid を static に変更 (base 初期化で使われるため)
  static ull euclid(ull a, ull b) {
    if(b != 0) return euclid(b, a % b);
    else return a;
  }

  // modPow を static に変更 (base 初期化で使われるため)
  static ull modPow(ull a, ull b) {
    ull res = 1;
    // getMod は static に変更したので RollingHash::getMod で呼び出す
    for(; b; a = RollingHash::getMod(a * a), b >>= 1) {
      if(b & 1) res = RollingHash::getMod(res * a);
    }
    return res;
  }
};

// static メンバの定義 (クラスの外で一度だけ定義が必要)
ull RollingHash::base = 0;
vector<ull> RollingHash::powr; // static メンバの定義を追加
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
      cout << (seg1.prod(l - 1, r).hash == seg2.prod(n - r, n - l + 1).hash ? "Yes" : "No") << endl;
    }
  }

  return 0;
}