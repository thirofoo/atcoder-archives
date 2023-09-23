/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc321/submissions/45846706
 * Submitted at: 2023-09-23 21:33:22
 * Problem URL: https://atcoder.jp/contests/abc321/tasks/abc321_d
 * Result: AC
 * Execution Time: 54 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m, p; cin >> n >> m >> p;
    vector<ll> a(n), b(m), br(m+1,0);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    rep(i,m) br[i+1] = br[i] + b[i];
    ll ans = 0;
    rep(i,n) {
        if( p-a[i] >= 0 ) {
            auto itr = lower_bound(b.begin(), b.end(), p-a[i]);
            ans += (br[itr - b.begin()] + a[i]*(itr - b.begin())) + p*(b.end()-itr);
        }
        else ans += m*p;
    }
    cout << ans << endl;
    
    return 0;
}