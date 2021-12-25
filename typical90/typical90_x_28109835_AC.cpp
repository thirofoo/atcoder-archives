/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28109835
 * Submitted at: 2021-12-25 20:42:30
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_x
 * Result: AC
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

int main() {
    ll n,k;
    ll sum = 0;
    cin >> n >> k;
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n)sum += abs(a[i]-b[i]);
    if(sum > k)return cout << "No" << endl,0;
    if((k-sum)%2 == 1)return cout << "No" << endl,0;
    cout << "Yes" << endl;
    return 0;
}