/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/44227161
 * Submitted at: 2023-08-04 16:54:55
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_f
 * Result: AC
 * Execution Time: 70 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,l; cin >> n >> l;
    priority_queue<ll,vector<ll>,greater<ll>> todo;
    ll total = 0;
    rep(i,n) {
        ll a; cin >> a;
        todo.push(a);
        total += a;
    }
    if( l != total ) todo.push(l-total);
    ll ans = 0;
    while( todo.size() > 1 ) {
        ll c1 = todo.top(); todo.pop();
        ll c2 = todo.top(); todo.pop();
        ans += c1 + c2;
        todo.push(c1+c2);
    }
    cout << ans << endl;
    
    return 0;
}