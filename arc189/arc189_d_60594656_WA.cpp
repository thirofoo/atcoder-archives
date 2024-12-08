/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc189/submissions/60594656
 * Submitted at: 2024-12-08 22:59:56
 * Problem URL: https://atcoder.jp/contests/arc189/tasks/arc189_d
 * Result: WA
 * Execution Time: 137 ms
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

  using P = pair<ll, ll>;

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> left(n, 0), right(n, 0), ans(n, 0);
  iota(left.begin(), left.end(), 0);
  iota(right.begin(), right.end(), 0);

  vector<P> idx;
  rep(i, n) {
    bool flag = false;
    if(i != 0) flag |= (a[i] > a[i - 1]);
    if(i != n - 1) flag |= (a[i] > a[i + 1]);
    if(!flag) ans[i] = a[i];
    else idx.emplace_back(P(a[i], i));
  }
  sort(idx.begin(), idx.end());

  dsu uf(n);
  rep(i, idx.size()) {
    auto [_, pos] = idx[i];
    ll val        = a[uf.leader(pos)];
    ll l = left[uf.leader(pos)], r = right[uf.leader(pos)];
    // cerr << "initial pos: " << pos << '\n';
    // cerr << "initial val: " << val << '\n';
    // cerr << "initial l: " << l << " r: " << r << "\n\n";
    while(true) {
      if(l != 0 && a[l - 1] < val) {
        ll next_l = left[uf.leader(l - 1)];
        uf.merge(l - 1, pos);
        val += a[l - 1];
        l = next_l;
      } else if(r != n - 1 && a[r + 1] < val) {
        ll next_r = right[uf.leader(r + 1)];
        uf.merge(r + 1, pos);
        val += a[r + 1];
        r = next_r;
      } else break;
    }
    left[uf.leader(pos)]  = l;
    right[uf.leader(pos)] = r;
    a[uf.leader(pos)]     = val;
    ans[pos]              = val;
    // cerr << "pos: " << pos << '\n';
    // cerr << "val: " << val << '\n';
    // cerr << "l: " << l << " r: " << r << "\n\n";
  }
  rep(i, n) cout << ans[i] << " ";
  cout << '\n';

  return 0;
}