/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc084/submissions/50671857
 * Submitted at: 2024-02-27 10:45:05
 * Problem URL: https://atcoder.jp/contests/abc084/tasks/abc084_d
 * Result: AC
 * Execution Time: 264 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

// 素因数分解 (未圧縮ver)
vector<ll> factorize(ll n) {
  vector<ll> pf;
  ll a = n;
  for(ll i=2; i*i<=n; i++) {
      ll cnt = 0;
      while( a%i == 0 ) {
          pf.emplace_back(i);
          a /= i;
      }
  }
  if( a != 1 ) pf.emplace_back(a);
  return pf;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll q; cin >> q;
    vector<ll> cnt(200000, 0);
    reps(i,1,200000) {
        if( i%2 == 0 ) continue;
        vector<ll> f1 = factorize(i), f2 = factorize((i+1)/2);
        if( f1.size() == 1 && f2.size() == 1 ) cnt[i] = 1;
    }
    reps(i,1,200000) cnt[i] += cnt[i-1];
    while( q-- ) {
        ll l, r; cin >> l >> r; l--;
        cout << cnt[r]-cnt[l] << endl;
    }
    
    return 0;
}