/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28232170
 * Submitted at: 2021-12-30 14:51:21
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bc
 * Result: WA
 * Execution Time: 601 ms
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
    rep(i,n){
        cin >> a; a %= p;
        nu[i] = a;
    }
    rep(i,n)rep(j,i)rep(k,j)rep(l,k)rep(m,l)if((nu[i]*nu[j]*nu[k]*nu[l]*nu[m])%p == q)count++;
    cout << count << endl;
    return 0;
}