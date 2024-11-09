/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/59590874
 * Submitted at: 2024-11-09 21:33:30
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_d
 * Result: AC
 * Execution Time: 195 ms
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

  ll q;
  cin >> q;
  vector<ll> plant;
  ll today = 0, done = 0;
  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) plant.emplace_back(today);
    else if(t == 2) {
      ll T;
      cin >> T;
      today += T;
    } else {
      ll h;
      cin >> h;
      auto itr = upper_bound(plant.begin(), plant.end(), today - h);
      cout << itr - plant.begin() - done << endl;
      done += itr - plant.begin() - done;
    }
  }

  return 0;
}