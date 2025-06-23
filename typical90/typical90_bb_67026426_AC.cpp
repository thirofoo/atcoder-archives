/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67026426
 * Submitted at: 2025-06-23 21:35:34
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bb
 * Result: AC
 * Execution Time: 116 ms
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

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> authors(m);
  vector<vector<ll>> works(n);
  rep(i, m) {
    ll k;
    cin >> k;
    rep(j, k) {
      ll r;
      cin >> r;
      r--;
      authors[i].emplace_back(r);
      works[r].emplace_back(i);
    }
  }
  vector<ll> ans(n, INF);
  ans[0] = 0;
  queue<ll> q;
  set<ll> readed;
  rep(i, works[0].size()) {
    q.push(works[0][i]);
    readed.insert(works[0][i]);
  }

  ll idx = 1;
  while(true) {
    vector<ll> update;
    while(!q.empty()) {
      ll a = q.front();
      q.pop();
      for(ll w: authors[a]) {
        if(ans[w] != INF) continue;
        ans[w] = idx;
        update.emplace_back(w);
      }
    }
    for(ll i: update) {
      if(ans[i] != idx) continue;
      for(ll a: works[i]) {
        if(readed.count(a)) continue;
        readed.insert(a);
        q.push(a);
      }
    }
    if(q.empty()) break;
    idx++;
  }
  rep(i, n) cout << (ans[i] == INF ? -1 : ans[i]) << "\n";

  return 0;
}