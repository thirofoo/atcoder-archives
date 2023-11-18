/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc329/submissions/47687185
 * Submitted at: 2023-11-18 21:08:17
 * Problem URL: https://atcoder.jp/contests/abc329/tasks/abc329_d
 * Result: AC
 * Execution Time: 205 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> cnt(n+1,0);
    ll ans = 0;
    rep(i,m) {
        ll a; cin >> a;
        cnt[a]++;
        if( ans == 0 ) ans = a;
        else if( cnt[a] > cnt[ans] || (cnt[a] == cnt[ans] && a < ans) ) ans = a;
        cout << ans << endl;
    }

    
    return 0;
}