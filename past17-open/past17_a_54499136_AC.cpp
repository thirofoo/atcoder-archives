/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54499136
 * Submitted at: 2024-06-13 17:21:26
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_a
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
    
    ll h, w; cin >> h >> w;
    if( w * 100 * 100 < 20 * h * h ) cout << "A" << endl;
    else if( w * 100 * 100 < 25 * h * h ) cout << "B" << endl;
    else cout << "C" << endl;
    
    return 0;
}