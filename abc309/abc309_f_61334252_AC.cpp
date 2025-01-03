/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc309/submissions/61334252
 * Submitted at: 2025-01-03 15:41:49
 * Problem URL: https://atcoder.jp/contests/abc309/tasks/abc309_f
 * Result: AC
 * Execution Time: 215 ms
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

using S = ll;
S op(S l, S r) {
  return max(l, r);
}
S e() {
  return -1;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  using T = tuple<ll, ll, ll>;

  ll n;
  cin >> n;
  vector<T> boxes;
  vector<ll> comp;
  rep(i, n) {
    vector<ll> param;
    rep(_, 3) {
      ll v;
      cin >> v;
      param.emplace_back(v);
      comp.emplace_back(v);
    }
    sort(param.begin(), param.end());
    reverse(param.begin(), param.end());
    boxes.emplace_back(T(param[0], param[1], param[2]));
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  rep(i, n) {
    auto [v1, v2, v3] = boxes[i];
    v1                = lower_bound(comp.begin(), comp.end(), v1) - comp.begin();
    v2                = lower_bound(comp.begin(), comp.end(), v2) - comp.begin();
    v3                = lower_bound(comp.begin(), comp.end(), v3) - comp.begin();
    boxes[i]          = T(v1, v2, v3);
  }
  sort(boxes.begin(), boxes.end());
  reverse(boxes.begin(), boxes.end());

  bool ok = false;
  segtree<S, op, e> sg(comp.size() + 1);
  ll idx = 0, prev;
  while(idx < n) {
    ll next_idx = idx;
    prev        = -1;
    while(next_idx < n) {
      auto&& [v1, v2, v3] = boxes[next_idx];
      if(prev != -1 && v1 != prev) break;
      if(sg.prod(v2 + 1, comp.size() + 1) > v3) {
        ok = true;
        break;
      }
      next_idx++;
      prev = v1;
    }
    if(ok) break;

    for(ll i = idx; i < next_idx; i++) {
      auto&& [_, v2, v3] = boxes[i];
      sg.set(v2, max(sg.get(v2), v3));
    }
    swap(idx, next_idx);
  }
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}