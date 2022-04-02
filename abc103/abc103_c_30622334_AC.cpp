/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc103/submissions/30622334
 * Submitted at: 2022-04-02 18:23:34
 * Problem URL: https://atcoder.jp/contests/abc103/tasks/abc103_c
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
    int n; cin >> n;
    ll ans = 0;
    rep(i,n){
        int c; cin >> c;
        ans += c-1;
    }
    cout << ans << endl;
    return 0;
}