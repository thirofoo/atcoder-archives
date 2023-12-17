/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc065/submissions/48625493
 * Submitted at: 2023-12-17 23:43:12
 * Problem URL: https://atcoder.jp/contests/agc065/tasks/agc065_a
 * Result: WA
 * Execution Time: 845 ms
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
    ll max_ele = 0, min_ele = 1e16;
    rep(i,n) {
        cin >> a[i];
        a[i] %= k;
        tmp[mp[a[i]]].emplace_back(a[i]);
        mp[a[i]]++;
        max_ele = max(max_ele,a[i]);
        min_ele = min(min_ele,a[i]);
    }
    ll max_cnt = mp[max_ele], min_cnt = mp[min_ele];
    vector<ll> c;
    for(ll i=n-1; i>=0; i--) {
        sort(tmp[i].begin(), tmp[i].end());
        reverse(tmp[i].begin(), tmp[i].end());
        bool f = true;
        for(auto ele:tmp[i]) {
            if( ele == max_ele || ele == min_ele ) continue;
            c.emplace_back(ele);
            f = false;
        }
        if( f ) continue;
        if( min_cnt > 0 ) {
            c.emplace_back(min_ele);
            min_cnt--;
        }
        if( max_cnt > 0 ) {
            c.emplace_back(max_ele);
            max_cnt--;
        }
    }
    while( max_cnt > 0 || min_cnt > 0 ) {
        if( min_cnt > 0 ) {
            c.emplace_back(min_ele);
            min_cnt--;
        }
        if( max_cnt > 0 ) {
            c.emplace_back(max_ele);
            max_cnt--;
        }
    }
    rep(i,n) c.emplace_back(c[i]);
    swap(a,c);
    rep(i,2*n) cerr << a[i] << " ";
    cerr << '\n';

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