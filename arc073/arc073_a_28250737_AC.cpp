/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc073/submissions/28250737
 * Submitted at: 2021-12-31 11:14:28
 * Problem URL: https://atcoder.jp/contests/arc073/tasks/arc073_a
 * Result: AC
 * Execution Time: 67 ms
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
    int n,t; cin >> n >> t;
    ll count = 0;
    vector<ll> time(n);
    rep(i,n)cin >> time[i];
    rep(i,n){
        if(i == n-1){
            count += t;
            break;
        }
        if(time[i+1]-time[i] < t)count += time[i+1]-time[i];
        else count += t;
    }
    cout << count << endl;
    return 0;
}