/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc347/submissions/51800363
 * Submitted at: 2024-03-30 21:01:25
 * Problem URL: https://atcoder.jp/contests/abc347/tasks/abc347_a
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
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n), ans;
    rep(i,n) {
        cin >> a[i];
        if( a[i]%k == 0 ) ans.emplace_back( a[i]/k );
    }
    rep(i,ans.size()) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}