/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc162/submissions/50678047
 * Submitted at: 2024-02-27 16:59:51
 * Problem URL: https://atcoder.jp/contests/abc162/tasks/abc162_d
 * Result: AC
 * Execution Time: 29 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    
    ll n; cin >> n; string s; cin >> s;
    map<char, ll> mp;
    rep(i,n) mp[s[i]]++;
    ll ans = mp['R']*mp['G']*mp['B'];
    rep(mid,n) rep(d,n) {
        ll left = mid-d, right = mid+d;
        if( left < 0 || right >= n ) continue;
        if( s[left] == s[mid] || s[mid] == s[right] || s[right] == s[left] ) continue;
        ans--;
    }
    cout << ans << endl;
    
    return 0;
}