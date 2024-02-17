/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc341/submissions/50338633
 * Submitted at: 2024-02-17 21:06:19
 * Problem URL: https://atcoder.jp/contests/abc341/tasks/abc341_c
 * Result: WA
 * Execution Time: 464 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w, n; cin >> h >> w >> n;
    string t; cin >> t;
    vector<string> s(h);
    map<char, P> mp;
    mp['L'] = P(0, -1);
    mp['R'] = P(0, 1);
    mp['U'] = P(-1, 0);
    mp['D'] = P(1, 0);
    rep(i, h) cin >> s[i];
    ll ans = 0;
    for(ll i=1; i<h-1; i++) for(ll j=1; j<w-1; j++) {
        ll x = i, y = j;
        bool flag = true;
        rep(k, n) {
            auto [dx, dy] = mp[t[k]];
            ll nx = x+dx, ny = y+dy;
            if( s[nx][ny] == '#' ) {
                flag = false;
                break;
            }
        }
        if( flag ) ans++;
    }
    cout << ans << endl;
    
    return 0;
}