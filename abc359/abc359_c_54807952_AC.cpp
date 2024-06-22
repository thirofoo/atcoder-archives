/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc359/submissions/54807952
 * Submitted at: 2024-06-22 21:11:50
 * Problem URL: https://atcoder.jp/contests/abc359/tasks/abc359_c
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
    
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    ll ans = abs(sy-ty);
    if(sx < tx) {
        if((sx+sy)%2 == 1) {
            // タイルの右の時
            ll adv = ans;
            ans += max((abs(sx-tx)-adv+1) / 2, 0ll);
        }
        else {
            // タイルの左の時
            ll adv = ans + 1;
            ans += max((abs(sx-tx)-adv+1) / 2, 0ll);
        }
    }
    else {
        if((sx+sy)%2 == 1) {
            // タイルの右の時
            ll adv = ans + 1;
            ans += max((abs(sx-tx)-adv+1) / 2, 0ll);
        }
        else {
            // タイルの左の時
            ll adv = ans;
            ans += max((abs(sx-tx)-adv+1) / 2, 0ll);
        }
    }
    cout << ans << '\n';
    
    return 0;
}