/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc196/submissions/30605509
 * Submitted at: 2022-04-01 18:27:52
 * Problem URL: https://atcoder.jp/contests/abc196/tasks/abc196_b
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    string x,ans = ""; cin >> x;
    rep(i,x.size()){
        if(x[i] == '.')break;
        ans += x[i];
    }
    cout << ans << endl;

    return 0;
}