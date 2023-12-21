/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc138/submissions/48689674
 * Submitted at: 2023-12-21 16:04:28
 * Problem URL: https://atcoder.jp/contests/arc138/tasks/arc138_c
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
    
    ll n; cin >> n;
    vector<ll> v(n), b(n+1,1);
    vector<P> a;
    rep(i,n) {
        cin >> v[i];
        a.emplace_back(P(v[i],i+1));
    }
    sort(a.begin(), a.end());
    b[0] = 0;
    ll ans = 0;
    for(ll i=n/2; i<n; i++) {
        auto [ele,idx] = a[i];
        b[idx] = -1;
        ans += ele;
    }
    ll mini = 1e16;
    rep(i,n) {
        b[i+1] += b[i];
        mini = min(mini, b[i+1]);
    }
    cout << n+mini << " " << ans << endl;
    
    return 0;
}