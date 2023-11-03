/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc024/submissions/47173003
 * Submitted at: 2023-11-03 15:04:15
 * Problem URL: https://atcoder.jp/contests/arc024/tasks/arc024_2
 * Result: AC
 * Execution Time: 6 ms
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
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    bool f = true;
    rep(i,n-1) f &= (c[i] == c[i+1]);
    if( f ) return cout << -1 << endl, 0;
    rep(i,n) c.emplace_back(c[i]);
    ll now = -1, cnt = 0, maxi = 0;
    rep(i,2*n) {
        if( now == c[i] ) cnt++;
        else {
            maxi = max(maxi, cnt);
            now = c[i];
            cnt = 1;
        }
    }
    maxi = max(maxi, cnt);
    cout << (maxi-1)/2 + 1 << endl;
    
    return 0;
}