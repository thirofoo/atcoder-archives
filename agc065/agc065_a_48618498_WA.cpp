/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc065/submissions/48618498
 * Submitted at: 2023-12-17 21:19:52
 * Problem URL: https://atcoder.jp/contests/agc065/tasks/agc065_a
 * Result: WA
 * Execution Time: 26 ms
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
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i] %= k;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    // rep(i,n) cerr << a[i] << " ";
    // cerr << '\n';
    ll ans1 = 0;
    rep(i,n-1) ans1 += ((a[i+1]-a[i])%k+k)%k;
    // cout << ans1 << endl;
    rep(i,n-1) {
        if( ((a[i+1]-a[i])%k+k)%k <= ((a[i]-a[i+1])%k+k)%k ) {
            swap(a[i+1], a[i]);
            break;
        }
    }
    ll ans2 = 0;
    rep(i,n-1) ans2 += ((a[i+1]-a[i])%k+k)%k;
    cout << max(ans1,ans2) << endl;
    
    return 0;
}