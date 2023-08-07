/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc065/submissions/44355417
 * Submitted at: 2023-08-07 14:32:00
 * Problem URL: https://atcoder.jp/contests/abc065/tasks/arc076_b
 * Result: AC
 * Execution Time: 133 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<P> x(n), y(n);
    rep(i,n) {
        cin >> x[i].first >> y[i].first;
        x[i].second = i;
        y[i].second = i;
    }
    x.push_back(P(-1e16,-1)), x.push_back(P(1e16,-1));
    y.push_back(P(-1e16,-1)), y.push_back(P(1e16,-1));
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    priority_queue<T,vector<T>,greater<T>> todo;
    for(ll i=1;i<=n;i++) {
        if( x[i-1].second != -1 ) todo.push(T(abs(x[i].first-x[i-1].first),x[i].second,x[i-1].second));
        if( x[i+1].second != -1 ) todo.push(T(abs(x[i].first-x[i+1].first),x[i].second,x[i+1].second));
        if( y[i-1].second != -1 ) todo.push(T(abs(y[i].first-y[i-1].first),y[i].second,y[i-1].second));
        if( y[i+1].second != -1 ) todo.push(T(abs(y[i].first-y[i+1].first),y[i].second,y[i+1].second));
    }
    dsu uf(n);
    ll ans = 0;
    while( !todo.empty() ) {
        auto [cost, i, j] = todo.top(); todo.pop();
        // cout << i << " " << j << endl << flush;
        if( uf.same(i,j) ) continue;
        uf.merge(i,j);
        ans += cost;
    }
    cout << ans << endl;
    
    return 0;
}