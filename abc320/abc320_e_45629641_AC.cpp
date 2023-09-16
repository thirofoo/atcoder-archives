/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc320/submissions/45629641
 * Submitted at: 2023-09-16 22:03:41
 * Problem URL: https://atcoder.jp/contests/abc320/tasks/abc320_e
 * Result: AC
 * Execution Time: 291 ms
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
    
    ll n, m; cin >> n >> m;
    set<ll> st;
    rep(i,n) st.insert(i);
    priority_queue<P,vector<P>,greater<P>> todo;
    vector<ll> ans(n,0);
    rep(i,m) {
        ll t, w, s; cin >> t >> w >> s;
        while( !todo.empty() ) {
            auto [tt,idx] = todo.top();
            if( tt <= t ) {
                st.insert(idx);
                todo.pop();
            }
            else break;
        }
        if( !st.empty() ) {
            ans[(*st.begin())] += w;
            todo.push(P(t+s,(*st.begin())) );
            st.erase(st.begin());
        }
    }
    rep(i,n) cout << ans[i] << endl;
    
    return 0;
}