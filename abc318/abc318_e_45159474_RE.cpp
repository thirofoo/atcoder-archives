/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc318/submissions/45159474
 * Submitted at: 2023-09-02 21:38:22
 * Problem URL: https://atcoder.jp/contests/abc318/tasks/abc318_e
 * Result: RE
 * Execution Time: 92 ms
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
    vector<ll> a(n), left(100005,0), right(100005,0);
    rep(i,n) {
        cin >> a[i];
        if( i ) right[a[i]]++;
    }
    ll ans = 0, now_num = 0;
    rep(i,n-1) {
        ans += now_num - left[a[i]] * right[a[i]];



        if( a[i] == a[i+1] ) {
            now_num -= left[a[i]] * right[a[i]];
            left[a[i]]++;
            right[a[i]]--;
            now_num += left[a[i]] * right[a[i]];
        }
        else {
            now_num -= left[a[i]] * right[a[i]];
            now_num -= left[a[i+1]] * right[a[i+1]];
            left[a[i]]++;
            right[a[i+1]]--;
            now_num += left[a[i]] * right[a[i]];
            now_num += left[a[i+1]] * right[a[i+1]];
        }

        // cout << ans << " " << now_num << endl;
    }
    cout << ans << endl;
    
    return 0;
}