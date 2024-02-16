/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc265/submissions/50297472
 * Submitted at: 2024-02-16 10:26:28
 * Problem URL: https://atcoder.jp/contests/abc265/tasks/abc265_e
 * Result: WA
 * Execution Time: 2127 ms
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
    
    ll n, m; cin >> n >> m;
    ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    set<P> st;
    rep(i, n) {
        ll x, y; cin >> x >> y;
        st.insert(P(x,y));
    }
    // 状態数少なさそう…？
    map<P,mint> dp;
    dp[P(0,0)] = 1;
    rep(i,n) {
        map<P,mint> ndp;
        for(auto &&[p,v] : dp) {
            auto &&[x,y] = p;
            if( !st.count(P(x+a,y+b)) ) ndp[P(x+a,y+b)] += dp[P(x,y)];
            if( !st.count(P(x+c,y+d)) ) ndp[P(x+c,y+d)] += dp[P(x,y)];
            if( !st.count(P(x+e,y+f)) ) ndp[P(x+e,y+f)] += dp[P(x,y)];
        }
        dp = ndp;
    }
    mint ans = 0;
    for(auto &&[_,v] : dp) ans += v;
    cout << ans.val() << endl;
    
    return 0;
}