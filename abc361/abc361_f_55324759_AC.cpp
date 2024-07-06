/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc361/submissions/55324759
 * Submitted at: 2024-07-07 00:17:11
 * Problem URL: https://atcoder.jp/contests/abc361/tasks/abc361_f
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

// 素因数分解 (未圧縮ver)
set<ll> factorize(ll n) {
  set<ll> pf;
  ll a = n;
  for(ll i=2; i*i<=n; i++) {
      ll cnt = 0;
      while( a%i == 0 ) {
          pf.insert(i);
          a /= i;
      }
  }
  if( a != 1 ) pf.insert(a);
  return pf;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> cnt(61, 0);
    auto rui = [&](ll r, ll num) {
        // r^n を求める関数
        // ※ ただオーバーフローする時は INF 
        ll res = 1;
        while(num--) {
            if(res > n / r) return INF;
            res *= r;
        }
        return res;
    };

    ll ans = 1;
    for(ll i=2; i<=60; i++) {
        ll left = 0, right = 1e9 + 5;
        while(right - left > 1) {
            ll mid = (left + right) / 2;
            if(rui(mid, i) <= n) left = mid;
            else right = mid;
        }
        set<ll> pf = factorize(i);
        ll now = 1;
        for(auto p : pf) now *= p;
        if(now != i) continue;
        cnt[i] = left-1;
        ans += cnt[i] * (pf.size() % 2 == 1 ? 1 : -1);
    }
    cout << ans << endl;
    
    return 0;
}