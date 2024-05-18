/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc354/submissions/53643920
 * Submitted at: 2024-05-19 00:15:46
 * Problem URL: https://atcoder.jp/contests/abc354/tasks/abc354_e
 * Result: AC
 * Execution Time: 60 ms
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
    vector<ll> a(n), b(n);
    rep(i,n) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    vector<bool> dp((1LL << n), false);
    dp[0] = false;
    rep(i,(1LL << n)) {
        bool ok = false;
        rep(j,n) {
            if( !(i & (1LL << j)) ) continue;
            reps(k,j+1,n) {
                if( !(i & (1LL << k)) ) continue;
                if( a[j] != a[k] && b[j] != b[k] ) continue;
                ll pb = i ^ (1LL << j) ^ (1LL << k);
                ok |= !dp[pb];
            }
        }
        dp[i] = ok;
    }
    cout << (dp[(1LL << n)-1] ? "Takahashi" : "Aoki") << endl;
    
    return 0;
}