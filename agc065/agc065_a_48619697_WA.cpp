/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc065/submissions/48619697
 * Submitted at: 2023-12-17 21:38:53
 * Problem URL: https://atcoder.jp/contests/agc065/tasks/agc065_a
 * Result: WA
 * Execution Time: 32 ms
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
    rep(i,n) a.emplace_back(a[i]);
    ll ans = 0, cand;
    rep(i,n-1) ans += ((a[i+1]-a[i])%k+k)%k;
    cand = ans;
    for(ll i=0; i<n; i++) {
        cand -= ((a[(i+1)%n]-a[i])%k+k)%k;
        cand += ((a[(n+i)%n]-a[(n+i-1)%n])%k+k)%k;
        ans = max(ans,cand);
    }
    cout << ans << endl;
    
    return 0;
}