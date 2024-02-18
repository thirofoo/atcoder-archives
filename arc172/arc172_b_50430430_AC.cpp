/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc172/submissions/50430430
 * Submitted at: 2024-02-18 23:34:09
 * Problem URL: https://atcoder.jp/contests/arc172/tasks/arc172_b
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k, l; cin >> n >> k >> l;
    mint ans = 1;
    rep(i,n) ans *= l-min(i,n-k);
    cout << ans.val() << endl;
    
    return 0;
}