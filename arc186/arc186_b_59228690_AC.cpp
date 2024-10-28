/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc186/submissions/59228690
 * Submitted at: 2024-10-28 18:02:10
 * Problem URL: https://atcoder.jp/contests/arc186/tasks/arc186_b
 * Result: AC
 * Execution Time: 145 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll   = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  // 解説 AC
  // 1. 「条件を満たす順列が存在する」 ⇒ 大小関係が DAG になる
  // 2. 大小関係の推移律を利用すると、DAG の一部を利用して有効木を構築できる
  // 3. 各有向木におけるトポロジカルソートの仕方の個数の総積が答えになる
  // 4. トポロジカルソートは有向木であれば木 DP で求められる

  ll n;
  cin >> n;
  vector<ll> a(n + 1, 0), info(n + 1, -1);
  rep(i, n) {
    cin >> a[i + 1];
    info[a[i + 1]] = i + 1;
  }
  // 有向木の構築
  vector<vector<ll>> graph(n + 1);
  set<ll> st;
  rep(i, n) st.insert(i + 1);
  st.insert(INF);

  for(ll i = 1; i <= n; i++) {
    // i ⇒ info[i] と遡る辺の中で最小 index への辺が候補
    if(info[i] != -1) {
      graph[i].emplace_back(info[i]);
      st.erase(info[i]);
    }
    auto it = st.upper_bound(a[i]);
    if((*it) >= i) continue;
    graph[i].emplace_back(*it);
    st.erase(it);
  }

  // 木 DP でトポロジカルソートの個数を求める
  vector<mint> fact(n + 1, 1), r_fact(n + 1, 1);
  for(int i = 1; i <= n; i++) {
    fact[i]   = fact[i - 1] * i;
    r_fact[i] = (mint) 1 / fact[i];
  }
  auto nCr = [&](ll total, ll r) {
    return fact[total] * r_fact[r] * r_fact[total - r];
  };

  vector<mint> dp(n + 1, 1);
  vector<ll> size(n + 1, 1);
  auto f = [&](auto self, ll v, ll p) -> void {
    ll p_size = 0;
    for(auto &e: graph[v]) {
      if(e == p) continue;
      // 部分木同士は混ざってもトポロジカル順的には ok
      // ⇒ 部分木を merge する遷移が nCr で求まる
      // ※ 既出の部分木の並べ方に、新しい部分木を insert する方法は p_size C size[e] 通り
      self(self, e, v);
      p_size += size[e];
      dp[v] *= dp[e] * nCr(p_size, size[e]);
    }
    size[v] = p_size + 1;
    return;
  };

  mint ans = 1;
  ll rest  = n;
  for(ll i = 1; i <= n; i++) {
    // 有向木の根でない場合は continue
    if(st.find(i) == st.end()) continue;
    cerr << "root: " << i << endl;
    f(f, i, -1);
    // トポソの形状の数 * 有向木への数字割り当て
    ans *= dp[i] * nCr(rest, size[i]);
    rest -= size[i];
  }
  cout << ans.val() << endl;

  return 0;
}