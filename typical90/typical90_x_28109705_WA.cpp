/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28109705
 * Submitted at: 2021-12-25 20:36:47
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_x
 * Result: WA
 * Execution Time: 9 ms
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
    if((k-sum)%2 == 1)return cout << "No" << endl,0;
    cout << "No" << endl;
    return 0;
}