/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc413/submissions/67315941
 * Submitted at: 2025-07-05 21:20:27
 * Problem URL: https://atcoder.jp/contests/abc413/tasks/abc413_d
 * Result: AC
 * Execution Time: 46 ms
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

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    vector<ll> a(n), a1, a2;
    rep(i, n) {
      cin >> a[i];
      if(a[i] > 0) a1.emplace_back(a[i]);
      else a2.emplace_back(a[i]);
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end(), greater<ll>());

    bool ok = false, flag;
    if(a1.size() == n) {
      flag = true;
      rep(i, n - 1) flag &= (a1[i + 1] * a1[0] == a1[i] * a1[1]);
      ok |= flag;
    }
    if(a2.size() == n) {
      flag = true;
      rep(i, n - 1) flag &= (a2[i + 1] * a2[0] == a2[i] * a2[1]);
      ok |= flag;
    }

    vector<ll> v;
    flag = true;
    rep(i, n) {
      if(i % 2 == 0) {
        if((i / 2) >= a1.size()) {
          flag = false;
          break;
        }
        v.emplace_back(a1[i / 2]);
      } else {
        if((i / 2) >= a2.size()) {
          flag = false;
          break;
        }
        v.emplace_back(a2[i / 2]);
      }
    }
    if(flag) {
      rep(i, n - 1) flag &= (v[i + 1] * v[0] == v[i] * v[1]);
      ok |= flag;
    }

    v.clear();
    flag = true;
    rep(i, n) {
      if(i % 2 == 0) {
        if((i / 2) >= a2.size()) {
          flag = false;
          break;
        }
        v.emplace_back(a2[i / 2]);
      } else {
        if((i / 2) >= a1.size()) {
          flag = false;
          break;
        }
        v.emplace_back(a1[i / 2]);
      }
    }
    if(flag) {
      rep(i, n - 1) flag &= (v[i + 1] * v[0] == v[i] * v[1]);
      ok |= flag;
    }

    cout << (ok ? "Yes" : "No") << endl;
  }

  return 0;
}