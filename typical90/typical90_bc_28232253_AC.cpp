/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28232253
 * Submitted at: 2021-12-30 14:57:07
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bc
 * Result: AC
 * Execution Time: 755 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,p,q,a,count = 0; cin >> n >> p >> q;
    vector<ll> nu(n);
    rep(i,n)cin >> nu[i];
    rep(i,n)rep(j,i)rep(k,j)rep(l,k)rep(m,l)if((nu[i]%p*nu[j]%p*nu[k]%p*nu[l]%p*nu[m]%p)%p == q)count++;
    cout << count << endl;
    return 0;
}