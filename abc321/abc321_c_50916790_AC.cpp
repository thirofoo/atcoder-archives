/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc321/submissions/50916790
 * Submitted at: 2024-03-05 13:32:06
 * Problem URL: https://atcoder.jp/contests/abc321/tasks/abc321_c
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
    
    ll k; cin >> k;
    vector<ll> like;
    rep(i, 1ll << 10) {
        ll num = 0;
        rep(j,10) {
            if( !(i & (1ll << j)) ) continue;
            num = num * 10 + (9-j);
        }
        if( num != 0 ) like.emplace_back(num);
    }
    sort(like.begin(), like.end());
    cout << like[k-1] << endl;
    
    return 0;
}