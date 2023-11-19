/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc168/submissions/47759636
 * Submitted at: 2023-11-19 21:27:13
 * Problem URL: https://atcoder.jp/contests/arc168/tasks/arc168_b
 * Result: AC
 * Execution Time: 108 ms
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
    map<ll,ll> mp;
    ll x = 0, m = 0;
    rep(i,n) {
        cin >> a[i];
        x ^= a[i];
        mp[a[i]]++;
    }
    if( x != 0 ) return cout << -1 << endl, 0;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(auto ele:a) {
        if( mp[ele]%2 == 1 ) return cout << ele-1 << endl, 0;
    }
    cout << 0 << endl;
    
    return 0;
}