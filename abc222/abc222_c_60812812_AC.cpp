/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc222/submissions/60812812
 * Submitted at: 2024-12-15 22:37:53
 * Problem URL: https://atcoder.jp/contests/abc222/tasks/abc222_c
 * Result: AC
 * Execution Time: 2 ms
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
  vector<string> a(2 * n);
  rep(i, 2 * n) cin >> a[i];
  map<char, char> win = {
      {'G', 'C'},
      {'C', 'P'},
      {'P', 'G'}
  };
  vector<ll> rank(2 * n, 0), win_cnt(2 * n, 0);
  iota(rank.begin(), rank.end(), 0);

  rep(i, m) {
    for(ll j = 0; j < 2 * n; j += 2) {
      ll k = j + 1;
      if(win[a[rank[j]][i]] == a[rank[k]][i]) win_cnt[rank[j]]++;
      else if(win[a[rank[k]][i]] == a[rank[j]][i]) win_cnt[rank[k]]++;
    }
    vector<ll> next_rank(2 * n, 0);
    iota(next_rank.begin(), next_rank.end(), 0);
    sort(next_rank.begin(), next_rank.end(), [&](ll x, ll y) {
      if(win_cnt[x] == win_cnt[y]) return x < y;
      return win_cnt[x] > win_cnt[y];
    });
    rank = next_rank;
  }
  rep(i, 2 * n) cout << rank[i] + 1 << '\n';

  return 0;
}