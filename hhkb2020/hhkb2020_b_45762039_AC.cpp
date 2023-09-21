/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/hhkb2020/submissions/45762039
 * Submitted at: 2023-09-21 09:16:52
 * Problem URL: https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_b
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    ll ans = 0;
    rep(i,h) {
        rep(j,w) {
            if( i != h-1 && s[i][j] == '.' && s[i+1][j] == '.' ) ans++;
            if( j != w-1 && s[i][j] == '.' && s[i][j+1] == '.' ) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}