/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/29141150
 * Submitted at: 2022-02-07 15:07:55
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_c
 * Result: WA
 * Execution Time: 412 ms
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
    vector<int> ans(n);
    vector<int> s(n),t(n);
    rep(i,n){
        cin >> s[i] >> t[i];
    }
    ll time = t[0];
    ans[0] = time;
    for(int i=1;i<n;i++)ans[i] = min(t[i],ans[i-1]+s[i-1]);
    ans[0] = min(ans[0],ans[n-1]+s[n-1]);
    for(int i=1;i<n;i++)ans[i] = min(t[i],ans[i-1]+s[i-1]);
    rep(i,n)cout << ans[i] << endl;
    return 0;
}