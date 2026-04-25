/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc455/submissions/75253604
 * Submitted at: 2026-04-25 21:40:34
 * Problem URL: https://atcoder.jp/contests/abc455/tasks/abc455_d
 * Result: AC
 * Execution Time: 56 ms
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

  ll n, q;
  cin >> n >> q;
  vector<ll> child(n, -1), parent(n, -1), bottom(n, -1);
  iota(bottom.begin(), bottom.end(), 0);
  rep(i, q) {
    ll c, p;
    cin >> c >> p;
    c--, p--;
    if(bottom[c] == c) bottom[c] = -1;
    if(parent[c] != -1) child[parent[c]] = -1;
    child[p]  = c;
    parent[c] = p;
  }
  rep(i, n) {
    if(bottom[i] == -1) {
      cout << 0 << " ";
      continue;
    }
    ll now = bottom[i], ans = 1;
    while(child[now] != -1) {
      now = child[now];
      ans++;
    }
    cout << ans << " ";
  }
  cout << endl;

  return 0;
}