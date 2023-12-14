/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc080/submissions/48482435
 * Submitted at: 2023-12-14 13:35:06
 * Problem URL: https://atcoder.jp/contests/abc080/tasks/abc080_d
 * Result: WA
 * Execution Time: 42 ms
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
    
    ll n, c; cin >> n >> c;
    vector<vector<ll>> ch(c,vector<ll>(100005,0));
    rep(i,n) {
        ll s, t, ci; cin >> s >> t >> ci; ci--;
        ch[ci][s]++, ch[ci][t+1]--;
    }
    rep(i,c) rep(j,100004) ch[i][j+1] += ch[i][j];
    ll ans = 0;
    rep(i,100005) {
        ll cand = 0;
        rep(j,c) cand += ch[j][i];
        ans = max(ans,cand);
    }
    cout << ans << endl;
    
    return 0;
}