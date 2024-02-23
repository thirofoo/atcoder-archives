/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/50524078
 * Submitted at: 2024-02-23 09:38:25
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_d
 * Result: AC
 * Execution Time: 14 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n), right(200005,0), left(200005,0);
    rep(i, n) cin >> a[i];
    
    // 中間全探索で包除っぽく
    ll ans = 0, same2 = 0, same3 = 0;
    reps(i,1,n) right[a[i]]++;
    rep(i,n) {
        ans += (i-left[a[i]]) * (n-i-1-right[a[i]]);
        ans -= same2;
        same3 = left[a[i]] * right[a[i]];
        ans += same3;

        same2 -= left[a[i]] * right[a[i]];
        if( i != n-1 && a[i] != a[i+1] ) same2 -= left[a[i+1]] * right[a[i+1]];

        left[a[i]]++;
        if( i != n-1 ) right[a[i+1]]--;

        same2 += left[a[i]] * right[a[i]];
        if( i != n-1 && a[i] != a[i+1] ) same2 += left[a[i+1]] * right[a[i+1]];
    }
    cout << ans << endl;
    
    return 0;
}