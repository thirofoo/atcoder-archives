/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc140/submissions/30622562
 * Submitted at: 2022-04-02 18:34:22
 * Problem URL: https://atcoder.jp/contests/abc140/tasks/abc140_b
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
    vector<int> a(n),b(n),c(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    for(int i=1;i<n;i++)cin >> c[i];

    int ans = 0;
    rep(i,n){
        ans += b[a[i]-1];
        if(i && a[i] == a[i-1]+1)ans += c[a[i]-1];
    }
    cout << ans << endl;
    return 0;
}