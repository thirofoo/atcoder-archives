/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/65163267
 * Submitted at: 2025-04-24 17:53:43
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_h
 * Result: AC
 * Execution Time: 168 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

template<typename Node>
struct Beats {
  int n, log;
  vector<Node> v;

  template<typename T>
  Beats(vector<T>& vc) {
    n = 1, log = 0;
    while(n < (int) vc.size()) n <<= 1, log++;
    v.resize(2 * n);
    for(int i = 0; i < (int) vc.size(); ++i) v[i + n] = Node(vc[i]);
    for(int i = n - 1; i; --i) _update(i);
  }

  template<typename T>
  void apply(int l, int r, T x) {
    if(l == r) return;
    l += n, r += n;
    for(int i = log; i >= 1; i--) {
      if(((l >> i) << i) != l) _push(l >> i);
      if(((r >> i) << i) != r) _push((r - 1) >> i);
    }
    {
      int l2 = l, r2 = r;
      while(l < r) {
        if(l & 1) _apply(l++, x);
        if(r & 1) _apply(--r, x);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }
    for(int i = 1; i <= log; i++) {
      if(((l >> i) << i) != l) _update(l >> i);
      if(((r >> i) << i) != r) _update((r - 1) >> i);
    }
  }

  template<typename F>
  void query(int l, int r, const F& f) {
    if(l == r) return;
    l += n, r += n;
    for(int i = log; i >= 1; i--) {
      if(((l >> i) << i) != l) _push(l >> i);
      if(((r >> i) << i) != r) _push((r - 1) >> i);
    }
    while(l < r) {
      if(l & 1) f(v[l++]);
      if(r & 1) f(v[--r]);
      l >>= 1;
      r >>= 1;
    }
  }

  private:
  void _push(int i) {
    v[i].push(v[2 * i + 0], v[2 * i + 1]);
  }
  void _update(int i) {
    v[i].update(v[2 * i + 0], v[2 * i + 1]);
  }
  template<typename T>
  void _apply(int i, T x) {
    bool res = v[i].apply(x);
    if(i < n && res == false) {
      _push(i);
      _apply(i * 2 + 0, x);
      _apply(i * 2 + 1, x);
      _update(i);
    }
  }
};

using T = long long;
using U = pair<int, int>;
struct Node {
  T sm, val;
  int size;
  bool same;
  Node(T n = 0): sm(n), val(n), size(1), same(true) {}

  void query2(T x) {
    sm = x * size, val = x, same = true;
  }
  void push(Node& l, Node& r) {
    if(same) l.query2(val), r.query2(val);
  }
  void update(Node& l, Node& r) {
    sm   = l.sm + r.sm;
    val  = l.val;
    size = l.size + r.size;
    same = l.same and r.same and l.val == r.val;
  }
  bool apply(U p) {
    if(p.first == 1) {
      return same ? (query2(val / p.second), true) : false;
    } else {
      return query2(p.second), true;
    }
  }
};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  Beats<Node> seg(a);

  while(q--) {
    ll t, l, r;
    cin >> t >> l >> r;
    l--;
    if(t == 1) {
      ll x;
      cin >> x;
      seg.apply(l, r, U{1, x});
    } else if(t == 2) {
      ll x;
      cin >> x;
      seg.apply(l, r, U{2, x});
    } else {
      ll ans = 0;
      seg.query(l, r, [&](Node& x) {
        ans += x.sm;
      });
      cout << ans << endl;
    }
  }

  return 0;
}
