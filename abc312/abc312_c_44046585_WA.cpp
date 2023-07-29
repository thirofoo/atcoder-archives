/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc312/submissions/44046585
 * Submitted at: 2023-07-29 21:19:54
 * Problem URL: https://atcoder.jp/contests/abc312/tasks/abc312_c
 * Result: WA
 * Execution Time: 79 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<ll> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll ans = b.back() + 1;
    rep(i,n){
        auto itr = lower_bound(b.begin(), b.end(), a[i]);
        if( (b.end()-itr) <= i+1 ) ans = min(ans, a[i]);
    }
    cout << ans << endl;
    
    return 0;
}