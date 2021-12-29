/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28214204
 * Submitted at: 2021-12-29 11:33:35
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_v
 * Result: WA
 * Execution Time: 8 ms
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

int euclid(ll x,ll y) {
    if(x%y != 0) return euclid(y,x%y);
    else return y;
}

int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    ll gcd = euclid(euclid(a,b),c);
    cout << (a/gcd -1)+(b/gcd -1)+(c/gcd -1) << endl; 
    return 0;
}