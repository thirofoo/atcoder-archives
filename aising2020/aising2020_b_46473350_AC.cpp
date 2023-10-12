/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/aising2020/submissions/46473350
 * Submitted at: 2023-10-12 18:21:39
 * Problem URL: https://atcoder.jp/contests/aising2020/tasks/aising2020_b
 * Result: AC
 * Execution Time: 1 ms
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
    ll ans = 0;
    rep(i,n) {
        cin >> a[i];
        if( i%2 == 0 && a[i]%2 == 1 ) ans++;
    }
    cout << ans << endl;

    
    return 0;
}