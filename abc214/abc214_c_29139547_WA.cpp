/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/29139547
 * Submitted at: 2022-02-07 13:05:28
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_c
 * Result: WA
 * Execution Time: 409 ms
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
    int n; cin >> n;
    vector<ll> s(n),t(n);
    rep(i,n)cin >> s[i];
    rep(i,n)cin >> t[i];
    ll time = t[0];
    cout << time << endl;
    for(int i=1;i<n;i++){
        time = min(time+s[i-1],t[i]);
        cout << time << endl;
    }
    return 0;
}