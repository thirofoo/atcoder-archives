/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc315/submissions/44716783
 * Submitted at: 2023-08-19 21:07:42
 * Problem URL: https://atcoder.jp/contests/abc315/tasks/abc315_c
 * Result: AC
 * Execution Time: 75 ms
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
    priority_queue<P> todo;
    rep(i,n) {
        ll f,s; cin >> f >> s;
        todo.push(P(s,f));
    }
    auto [s,f] = todo.top(); todo.pop();
    ll ans = 0;
    while( !todo.empty() ) {
        auto [ns,nf] = todo.top(); todo.pop();
        if( f == nf ) ans = max(ans,s+ns/2);
        else ans = max(ans,s+ns);
    }
    cout << ans << endl;
    
    return 0;
}