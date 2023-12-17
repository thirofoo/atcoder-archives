/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc065/submissions/48621234
 * Submitted at: 2023-12-17 22:07:16
 * Problem URL: https://atcoder.jp/contests/agc065/tasks/agc065_a
 * Result: WA
 * Execution Time: 145 ms
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
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    vector<vector<ll>> tmp(n);
    map<ll,ll> mp;
    rep(i,n) {
        cin >> a[i];
        a[i] %= k;
        tmp[mp[a[i]]].emplace_back(a[i]);
        mp[a[i]]++;
    }
    vector<ll> c;
    rep(i,n) {
        sort(tmp[i].begin(), tmp[i].end());
        reverse(tmp[i].begin(), tmp[i].end());
        for(auto ele:tmp[i]) c.emplace_back(ele);
    }
    rep(i,n) c.emplace_back(c[i]);
    swap(a,c);
    // rep(i,2*n) cerr << a[i] << " ";
    // cerr << '\n';

    ll ans = 0, cand;
    rep(i,n-1) ans += ((a[i+1]-a[i])%k+k)%k;
    cand = ans;
    for(ll i=0; i<n; i++) {
        cand -= ((a[(i+1)%n]-a[i])%k+k)%k;
        cand += ((a[(n+i)%n]-a[(n+i-1)%n])%k+k)%k;
        ans = max(ans,cand);
    }
    cout << ans << endl;
    
    return 0;
}