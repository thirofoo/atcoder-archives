/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/hhkb2020/submissions/49749550
 * Submitted at: 2024-01-28 02:05:53
 * Problem URL: https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_e
 * Result: AC
 * Execution Time: 271 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w; cin >> h >> w;
    vector<string> s(h);
    vector<vector<ll>> r(h,{-1}), c(w,{-1});
    rep(i,h) cin >> s[i];
    ll cnt = 0;
    rep(i,h) rep(j,w) {
        cnt += (s[i][j] == '.');
        if( s[i][j] == '#' ) {
            r[i].emplace_back(j);
            c[j].emplace_back(i);
        }
    }
    rep(i,h) r[i].emplace_back(w);
    rep(i,w) c[i].emplace_back(h);
    vector<mint> rui(h*w+1,1);
    for(ll i=1; i<=h*w; i++) rui[i] = rui[i-1]*2;
    mint ans = 0;
    rep(i,h) rep(j,w) {
        if( s[i][j] == '#' ) continue;
        auto itr1 = lower_bound(r[i].begin(), r[i].end(), j);
        auto itr2 = lower_bound(c[j].begin(), c[j].end(), i);
        ll bright = ((*itr1)-(*(itr1-1))-1) + ((*itr2)-(*(itr2-1))-1) - 1;
        ans += rui[cnt-bright] * (rui[bright] - 1);
    }
    cout << ans.val() << endl;
    
    return 0;
}