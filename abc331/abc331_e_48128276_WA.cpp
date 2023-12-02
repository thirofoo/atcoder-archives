/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc331/submissions/48128276
 * Submitted at: 2023-12-02 21:47:30
 * Problem URL: https://atcoder.jp/contests/abc331/tasks/abc331_e
 * Result: WA
 * Execution Time: 174 ms
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
    
    ll n, m, l; cin >> n >> m >> l;
    vector<P> a, b;
    rep(i,n) {
        ll t; cin >> t;
        a.emplace_back(P(t,i+1));
    }
    rep(i,m) {
        ll t; cin >> t;
        b.emplace_back(P(t,i+1));
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    set<P> st;
    priority_queue<T,vector<T>,greater<T>> pq;
    rep(i,l) {
        ll c, d; cin >> c >> d;
        st.insert(P(c,d));
    }
    rep(i,n) {
        rep(j,m) {
            if( pq.size() < l+1 ) pq.push(T(a[i].first+b[j].first,a[i].second,b[j].second));
            else {
                auto&& [total,ni,nj] = pq.top();
                if( total <= a[i].first+b[j].first ) {
                    pq.push(T(a[i].first+b[j].first,a[i].second,b[j].second));
                    pq.pop();
                }
                else break;
            }
        }
    }
    ll ans = 0;
    while( !pq.empty() ) {
        auto&& [total,ni,nj] = pq.top(); pq.pop();
        if( !st.count(P(ni,nj)) ) ans = max(ans,total);
    }
    cout << ans << endl;
    
    return 0;
}