/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc203/submissions/44376869
 * Submitted at: 2023-08-08 11:36:11
 * Problem URL: https://atcoder.jp/contests/abc203/tasks/abc203_d
 * Result: RE
 * Execution Time: 2206 ms
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
    
    ll n,k; cin >> n >> k;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    multiset<ll> st1, st2;
    rep(i,k)rep(j,k) st2.insert(a[i][j]);
    
    auto adjust = [&]() -> void {
        while(st1.empty() || (*st1.rbegin()) > (*st2.begin()) || st1.size() < st2.size()) {
            st1.insert(*st2.begin());
            st2.erase(st2.begin());
        }
        while( st1.size() > st2.size() ) {
            st2.insert(*st1.rbegin());
            auto itr = st1.end(); itr--;
            st1.erase(itr);
        }
        return;
    };
    adjust();

    ll ans = *st2.begin();
    rep(i,n-k+1) {
        if( i%2 == 0 ) {
            for(ll j=k;j<n;j++) {
                rep(l,k) {
                    // 前列削除
                    ll now = a[i+l][j-k];
                    if( st1.count(now) ) st1.erase(st1.find(now));
                    else st2.erase(st2.find(now));
                    // 後列追加
                    st2.insert(a[i+l][j]);
                }
                adjust(); // 数調整
                auto itr = st1.end(); itr--;
                ans = min(ans, *itr);
            }
            if( i != n-k ) {
                for(ll j=n-1;j>=n-k;j--) {
                    ll now = a[i][j];
                    if( st1.count(now) ) st1.erase(st1.find(now));
                    else st2.erase(st2.find(now));
                    st2.insert(a[i+k][j]);
                }
                adjust(); // 数調整
                auto itr = st1.end(); itr--;
                ans = min(ans, *itr);
            }
        }
        else {
            for(ll j=n-k-1;j>=0;j--) {
                rep(l,k) {
                    // 前列削除
                    ll now = a[i+l][j+k];
                    if( st1.count(now) ) st1.erase(st1.find(now));
                    else st2.erase(st2.find(now));
                    // 後列追加
                    st2.insert(a[i+l][j]);
                }
                adjust(); // 数調整
                auto itr = st1.end(); itr--;
                ans = min(ans, *itr);
            }
            if( i != n-k ) {
                for(ll j=0;j<k;j--) {
                    ll now = a[i][j];
                    if( st1.count(now) ) st1.erase(st1.find(now));
                    else st2.erase(st2.find(now));
                    st2.insert(a[i+k][j]);
                }
                adjust(); // 数調整
                auto itr = st1.end(); itr--;
                ans = min(ans, *itr);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}