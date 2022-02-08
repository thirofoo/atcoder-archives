/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc212/submissions/29167090
 * Submitted at: 2022-02-08 22:33:03
 * Problem URL: https://atcoder.jp/contests/abc212/tasks/abc212_c
 * Result: AC
 * Execution Time: 154 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m,ans = INT_MAX; cin >> n >> m;
    vector<int> a(n),b(m);
    rep(i,n)cin >> a[i];
    rep(i,m)cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    rep(i,m){
        int itr = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
        if(itr == n)ans = min(ans,b[i]-a[itr-1]);
        else if(itr == 0)ans = min(ans,a[itr]-b[i]);
        else ans = min(ans,min(b[i]-a[itr-1],a[itr]-b[i]));
    }
    cout << ans << endl;
    return 0;
}