/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc262/submissions/33670639
 * Submitted at: 2022-07-31 21:20:06
 * Problem URL: https://atcoder.jp/contests/abc262/tasks/abc262_c
 * Result: AC
 * Execution Time: 46 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    ll ans = 0;
    rep(i,n)if(a[a[i]-1] == i+1 && a[i] != i+1)ans++;
    ans /= 2;
    ll cnt = 0;
    rep(i,n)if(a[i] == i+1)cnt++;
    cout << ans + cnt*(cnt-1)/2 << endl;
    
    return 0;
}