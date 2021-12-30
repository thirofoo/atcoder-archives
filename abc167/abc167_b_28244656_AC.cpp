/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc167/submissions/28244656
 * Submitted at: 2021-12-31 01:30:16
 * Problem URL: https://atcoder.jp/contests/abc167/tasks/abc167_b
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
    int a,b,c,k,ans = 0; cin >> a >> b >> c >> k;
    vector<int> card(0);
    if(k < a)cout << k << endl;
    else if(k-a < b)cout << a << endl;
    else cout << a-(k-a-b) << endl;
    return 0;
}