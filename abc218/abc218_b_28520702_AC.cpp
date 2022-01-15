/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc218/submissions/28520702
 * Submitted at: 2022-01-15 16:44:59
 * Problem URL: https://atcoder.jp/contests/abc218/tasks/abc218_b
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
    string ans = "";
    rep(i,26){
        int a; cin >> a;
        ans += ('a'+a-1);
    }
    cout << ans << endl;
    return 0;
}