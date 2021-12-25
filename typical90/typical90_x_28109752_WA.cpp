/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28109752
 * Submitted at: 2021-12-25 20:39:06
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_x
 * Result: WA
 * Execution Time: 6 ms
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
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        sum += abs(a-b);
    }
    if(sum > k)return cout << "No" << endl,0;
    if(k%2 != sum%2)return cout << "No" << endl,0;
    cout << "Yes" << endl;
    return 0;
}