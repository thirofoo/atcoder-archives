/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc396/submissions/63530065
 * Submitted at: 2025-03-08 21:34:55
 * Problem URL: https://atcoder.jp/contests/abc396/tasks/abc396_e
 * Result: AC
 * Execution Time: 1464 ms
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

struct weighted_dsu {
  // ACLよりUF写経
  public:
  // expricit：コンストラクタに付与で暗黙の型変換無向化
  weighted_dsu(): _n(0) {}
  explicit weighted_dsu(ll n): _n(n), parent_or_size(n, -1), diff_weight(n, 0) {}

  ll merge(ll a, ll b, ll w) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);

    // weight[b] = weight[a] + w となるようにmerge
    // ※ 連結成分のmergeだから weightの差分が重みに反映
    w += weight(a);
    w -= weight(b);

    ll x = leader(a), y = leader(b);
    if(x == y) return x;
    if(-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y), w = -w;
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;

    diff_weight[y] = w;

    // 連結成分が大きい方のleaderが返り値
    return x;
  }

  bool same(ll a, ll b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  // 親ノードに行くまでがO(α(n))
  ll leader(ll a) {
    assert(0 <= a && a < _n);
    if(parent_or_size[a] < 0) return a;
    ll r = leader(parent_or_size[a]);
    diff_weight[a] += diff_weight[parent_or_size[a]];
    return parent_or_size[a] = r;
  }

  ll size(ll a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  ll weight(ll x) {
    leader(x); // 経路圧縮 (diffを現在の状態に反映)
    return diff_weight[x];
  }

  ll diff(ll x, ll y) {
    return weight(y) - weight(x);
  }

  std::vector<std::vector<ll>> groups() {
    std::vector<ll> leader_buf(_n), group_size(_n);
    for(ll i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<ll>> result(_n);
    for(ll i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for(ll i = 0; i < _n; i++) {
      result[leader_buf[i]].emplace_back(i);
    }
    result.erase(std::remove_if(result.begin(), result.end(),
                                [&](const std::vector<ll>& v) {
                                  return v.empty();
                                }),
                 result.end());
    return result;
  }

  private:
  ll _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<ll> parent_or_size;
  std::vector<ll> diff_weight;
};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  using T = tuple<ll, ll, ll>;
  vector<T> edges;
  rep(i, m) {
    ll x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    edges.emplace_back(x, y, z);
  }

  ll diff;
  vector<ll> ans(n, 0);
  using P = pair<ll, ll>;
  queue<P> q;
  rep(i, 40) {
    weighted_dsu uf(n);
    vector<vector<P>> graph(n);
    rep(j, m) {
      auto [x, y, z] = edges[j];
      if((z >> i) & 1) diff = 1;
      else diff = 0;
      if(uf.same(x, y)) {
        if(((uf.diff(x, y) % 2) + 2) % 2 != diff) {
          cout << -1 << '\n';
          return 0;
        }
      } else {
        uf.merge(x, y, diff);
        graph[x].emplace_back(y, diff);
        graph[y].emplace_back(x, diff);
      }
    }
    vector group = uf.groups();
    vector<ll> diffs(n, -1);
    for(auto& v: group) {
      q.push({v[0], 0});
      while(!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        diffs[u] = d;
        for(auto [to, w]: graph[u]) {
          if(diffs[to] != -1) continue;
          q.push({to, (w == 1 ? 1 - d : d)});
        }
      }
      ll diff_one_cnt = 0;
      for(auto x: v) diff_one_cnt += diffs[x];
      if(diff_one_cnt > v.size() / 2) {
        for(auto x: v) diffs[x] = 1 - diffs[x];
      }
      for(auto x: v) ans[x] |= (diffs[x] << i);
    }
  }
  rep(i, n) cout << ans[i] << " ";
  cout << '\n';

  return 0;
}