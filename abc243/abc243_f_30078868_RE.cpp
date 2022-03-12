/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc243/submissions/30078868
 * Submitted at: 2022-03-12 22:40:02
 * Problem URL: https://atcoder.jp/contests/abc243/tasks/abc243_f
 * Result: RE
 * Execution Time: 118 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

long long MOD = 998244353;

long long modPow(long long x, long long a) {
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long t = modPow(x, a / 2);
  return (t * t) % MOD;
}

long long modInv(long long x) {
  return modPow(x, MOD - 2);
}

int main() {
    int n,m,k; cin >> n >> m >> k;
    int total = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        total += a[i];
    }
    vector<vector<ll>> ans(k);
    ans[0] = a;
    rep(i,k-1){
        ans.push_back(convolution_ll(a,ans[i]));
    }
    cout << modInv(ans[k-1][m-1]) << endl;
    return 0;
}