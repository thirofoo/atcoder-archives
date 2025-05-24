/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc407/submissions/66129682
 * Submitted at: 2025-05-24 22:25:59
 * Problem URL: https://atcoder.jp/contests/abc407/tasks/abc407_f
 * Result: AC
 * Execution Time: 28 ms
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // a[i] が最大となる連続部分列を長さごとに数え上げられれば良さそう
  // k の増加に対して寄与は定数か線形っぽい

  vector<ll> prev(n), next(n), st;
  rep(i, n) {
    while(!st.empty() && a[st.back()] <= a[i]) st.pop_back();
    prev[i] = st.empty() ? -1 : st.back();
    st.emplace_back(i);
  }
  st.clear();
  for(ll i = n - 1; i >= 0; --i) {
    while(!st.empty() && a[st.back()] < a[i]) st.pop_back();
    next[i] = st.empty() ? n : st.back();
    st.emplace_back(i);
  }

  vector<ll> katamuki(n + 3), seppen(n + 3);
  auto add = [&](ll l, ll r, ll v1, ll v2) {
    if(l > r) return;
    katamuki[l] += v1;
    katamuki[r + 1] -= v1;
    seppen[l] += v2;
    seppen[r + 1] -= v2;
  };

  rep(i, n) {
    ll v = a[i];
    ll l = i - prev[i], r = next[i] - i;
    ll small = min(l, r), large = max(l, r);

    add(1, small, v, 0);
    if(large >= small + 1) add(small + 1, large, 0, v * small);
    ll nl = large + 1, nr = l + r - 1;
    if(nl <= nr) add(nl, nr, -v, v * (l + r));
  }
  ll cur_s = 0, cur_i = 0;
  for(ll k = 1; k <= n; ++k) {
    cur_s += katamuki[k];
    cur_i += seppen[k];
    cout << cur_s * k + cur_i << '\n';
  }

  return 0;
}
