/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc186/submissions/31463325
 * Submitted at: 2022-05-06 12:55:05
 * Problem URL: https://atcoder.jp/contests/abc186/tasks/abc186_d
 * Result: WA
 * Execution Time: 47 ms
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
    
    int n; cin >> n;
    vector<int> a(n),m(n);
    rep(i,n)cin >> a[i];
    sort(a.begin(),a.end());
    m[0] = a[0];
    rep(i,n-1)m[i+1] = m[i]+a[i+1];
    ll ans = 0;
    for(int i=1;i<n;i++){
        ans += a[i]*i - m[i-1];
    }
    cout << ans << endl;
    return 0;
}