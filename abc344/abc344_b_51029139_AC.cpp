/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc344/submissions/51029139
 * Submitted at: 2024-03-09 21:04:19
 * Problem URL: https://atcoder.jp/contests/abc344/tasks/abc344_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    stack<ll> ans;
    while( true ) {
        ll a; cin >> a;
        ans.push(a);
        if( a == 0 ) break;
    }
    while( !ans.empty() ) {
        cout << ans.top() << endl;
        ans.pop();
    }
    
    return 0;
}