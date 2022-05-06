/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc186/submissions/31463098
 * Submitted at: 2022-05-06 12:35:18
 * Problem URL: https://atcoder.jp/contests/abc186/tasks/abc186_b
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int h,w,tmp = INT_MAX; cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w){
        cin >> a[i][j];
        tmp = min(tmp,a[i][j]);
    }

    int ans = 0;
    rep(i,h)rep(j,w)ans += a[i][j]-tmp;
    cout << ans << endl;
    

    return 0;
}