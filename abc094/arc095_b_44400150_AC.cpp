/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc094/submissions/44400150
 * Submitted at: 2023-08-09 10:07:19
 * Problem URL: https://atcoder.jp/contests/abc094/tasks/arc095_b
 * Result: AC
 * Execution Time: 25 ms
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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    ll max_ele = a.back();
    a.pop_back();

    ll ans = 0, mini = 1e16;
    rep(i,n-1) {
        if( min(abs(max_ele/2-a[i]),abs(max_ele/2+1-a[i])) < mini ) {
            mini = min(abs(max_ele/2-a[i]),abs(max_ele/2+1-a[i]));
            ans = a[i];
        }
    }
    cout << max_ele << " " << ans << endl;
    
    return 0;
}