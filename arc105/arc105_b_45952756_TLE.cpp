/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc105/submissions/45952756
 * Submitted at: 2023-09-26 09:25:02
 * Problem URL: https://atcoder.jp/contests/arc105/tasks/arc105_b
 * Result: TLE
 * Execution Time: 2207 ms
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
    priority_queue<ll> todo;
    ll min_ele = 1e9;
    rep(i,n) {
        ll a; cin >> a;
        todo.push(a);
        min_ele = min(min_ele,a);
    }
    while( true ) {
        ll max_ele = todo.top(); todo.pop();
        if( max_ele == min_ele ) {
            cout << max_ele << endl;
            return 0;
        }
        ll n_ele = max_ele-min_ele;
        min_ele = min(min_ele, n_ele);
        todo.push(n_ele);
    }
    
    return 0;
}