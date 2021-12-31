/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc179/submissions/28250132
 * Submitted at: 2021-12-31 10:30:01
 * Problem URL: https://atcoder.jp/contests/abc179/tasks/abc179_b
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
    int n,count = 0; cin >> n;
    rep(i,n){
        int a,b; cin >> a >> b;
        if(a == b)count++;
        else count = 0;
        if(count == 3)return cout << "Yes" << endl,0;
    }
    cout << "No" << endl;
    return 0;
}