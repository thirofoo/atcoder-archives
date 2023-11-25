/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc330/submissions/47915205
 * Submitted at: 2023-11-25 21:30:23
 * Problem URL: https://atcoder.jp/contests/abc330/tasks/abc330_e
 * Result: AC
 * Execution Time: 1356 ms
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
    
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    map<ll,ll> mp;
    set<ll> st;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    rep(i,3*n) if( mp[i] == 0 ) st.insert(i);
    while(q--) {
        ll i, x; cin >> i >> x; i--;
        if( mp[a[i]] == 1 ) st.insert(a[i]);
        mp[a[i]]--;
        if( mp[x] == 0 && st.count(x) ) st.erase(st.lower_bound(x));
        mp[x]++;
        a[i] = x;
        cout << (*(st.begin())) << endl;
    }
    
    return 0;
}