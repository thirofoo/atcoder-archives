/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc371/submissions/57754368
 * Submitted at: 2024-09-14 21:19:46
 * Problem URL: https://atcoder.jp/contests/abc371/tasks/abc371_d
 * Result: AC
 * Execution Time: 316 ms
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

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> x(n), p(n), comp;
  rep(i, n) {
    cin >> x[i];
    comp.push_back(x[i]);
  }
  rep(i, n) cin >> p[i];
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  fenwick_tree<ll> fw(n);
  rep(i, n) {
    x[i] = lower_bound(comp.begin(), comp.end(), x[i]) - comp.begin();
    fw.add(x[i], p[i]);
  }

  ll q;
  cin >> q;
  while(q--) {
    ll l, r;
    cin >> l >> r;
    ll left  = lower_bound(comp.begin(), comp.end(), l) - comp.begin();
    ll right = upper_bound(comp.begin(), comp.end(), r) - comp.begin();
    cout << fw.sum(left, right) << endl;
  }

  return 0;
}