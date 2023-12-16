/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc333/submissions/48578538
 * Submitted at: 2023-12-16 21:49:35
 * Problem URL: https://atcoder.jp/contests/abc333/tasks/abc333_e
 * Result: AC
 * Execution Time: 58 ms
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
    vector<vector<ll>> portion(n+1);
    vector<P> q;
    rep(i,n) {
        ll t, x; cin >> t >> x;
        if( t == 1 ) portion[x].emplace_back(i);
        q.emplace_back(P(t,x));
    }
    vector<bool> ans(n,false);
    for(ll i=q.size()-1; i>=0; i--) {
        if( q[i].first == 1 ) continue;
        while( !portion[q[i].second].empty() && portion[q[i].second].back() >= i ) portion[q[i].second].pop_back();
        if( portion[q[i].second].empty() ) return cout << -1 << endl, 0;
        ans[portion[q[i].second].back()] = true;
        portion[q[i].second].pop_back();
    }
    ll num = 0, now = 0;
    rep(i,n) {
        if( q[i].first == 1 ) now += ans[i];
        else now--;
        num = max(num,now);
    }
    cout << num << endl;
    rep(i,n) {
        if( q[i].first == 2 ) continue;
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}