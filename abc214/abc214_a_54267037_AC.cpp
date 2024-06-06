/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/54267037
 * Submitted at: 2024-06-06 14:00:38
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_a
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    if(n <= 125) cout << 4 << endl;
    else if(n <= 211) cout << 6 << endl;
    else cout << 8 << endl;
    
    return 0;
}