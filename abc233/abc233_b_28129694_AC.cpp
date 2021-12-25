/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc233/submissions/28129694
 * Submitted at: 2021-12-25 21:32:23
 * Problem URL: https://atcoder.jp/contests/abc233/tasks/abc233_b
 * Result: AC
 * Execution Time: 13 ms
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
    int l,r,R;
    string s,ans;
    cin >> l >> r >> s;
    R = r;
    ans = s;
    for(int i=l-1;i<r;i++){
      ans[i] = s[R-1];
      R--;
    }
    cout << ans << endl;
    return 0;
}