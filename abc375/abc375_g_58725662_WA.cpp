/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc375/submissions/58725662
 * Submitted at: 2024-10-12 22:38:29
 * Problem URL: https://atcoder.jp/contests/abc375/tasks/abc375_g
 * Result: WA
 * Execution Time: 317 ms
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
    leader(x); // 経路圧縮 ( diffを現在の状態に反映 )
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

  using P = pair<ll, ll>;
  using T = tuple<ll, ll, ll>;

  ll n, m;
  cin >> n >> m;
  vector<ll> a(m), b(m), c(m);
  vector<vector<ll>> graph(n);
  rep(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--, b[i]--;
    graph[a[i]].emplace_back(i);
    graph[b[i]].emplace_back(i);
  }
  // 無難に dijkstra + 経路復元
  vector<ll> dist(n, INF);
  vector<P> prev(n); // P(前の頂点, 辺 idx)
  priority_queue<P, vector<P>, greater<P>> pq;
  dist[0] = 0;
  pq.emplace(0, 0);
  while(!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if(dist[v] < d) continue;
    for(auto e: graph[v]) {
      ll u = (a[e] == v ? b[e] : a[e]);
      if(dist[u] > dist[v] + c[e]) {
        dist[u] = dist[v] + c[e];
        prev[u] = P(v, e);
        pq.emplace(dist[u], u);
      }
    }
  }
  // 経路復元して最短経路で用いられている辺を set に入れる
  weighted_dsu uf(n);
  set<ll> used;
  ll cur = n - 1;
  while(cur != 0) {
    auto [prev_v, e] = prev[cur];
    used.insert(e);
    uf.merge(prev_v, cur, c[e]);
    cur = prev_v;
  }

  // コストが小さい辺 && 使われていない辺を使って wuf
  vector<ll> perm(m);
  iota(perm.begin(), perm.end(), 0);
  sort(perm.begin(), perm.end(), [&](ll i, ll j) {
    return c[i] < c[j];
  });
  dsu uf2(n);
  rep(i, m) {
    ll e = perm[i];
    if(used.find(e) != used.end()) continue;
    if(uf.same(a[e], b[e])) {
      ll nc = (dist[a[e]] <= dist[b[e]] ? uf.weight(b[e]) : uf.weight(a[e])) + c[e];
      if(uf.diff(a[e], b[e]) == nc) {
        if(dist[a[e]] < dist[b[e]]) uf.merge(b[e], a[e], c[e]);
        else uf.merge(a[e], b[e], c[e]);
        uf2.merge(a[e], b[e]);
      }
    } else {
      if(dist[a[e]] < dist[b[e]]) uf.merge(b[e], a[e], c[e]);
      else uf.merge(a[e], b[e], c[e]);
      uf2.merge(a[e], b[e]);
    }
  }
  rep(i, m) {
    if(used.find(i) == used.end()) cout << "No" << '\n';
    else cout << (uf2.same(a[i], b[i]) ? "No" : "Yes") << '\n';
  }

  return 0;
}