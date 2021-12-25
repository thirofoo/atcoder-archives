/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28109412
 * Submitted at: 2021-12-25 20:21:22
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_x
 * Result: WA
 * Execution Time: 7 ms
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
    int n,k;
    ll sum = 0;
    cin >> n >> k;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        sum += max(a,b) - min(a,b);
    }
    if(sum > k)cout << "No" << endl;
    else if((k-sum)%2 == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}