/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/49666997
 * Submitted at: 2024-01-26 18:02:42
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_f
 * Result: AC
 * Execution Time: 737 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<P> sx, gx, sy, gy;
    ll num_x = n/2, num_y = (n+1)/2;
    auto calc = [&](ll num, ll sp, ll s_idx, vector<P> &v) -> void {
        rep(i,(1LL << num)) {
            ll now = sp;
            rep(j,num) now += a[2*j+s_idx]*(i & (1LL << j) ? 1 : -1 );
            v.emplace_back(P(now, i));
        }
    };
    // X, Y 独立に Start, Goal からの遷移 bit 全探索 part
    calc(num_x/2, 0, 1, sx);
    calc(num_y/2, 0, 0, sy);
    calc(num_x-num_x/2, x, 2*(num_x/2)+1, gx);
    calc(num_y-num_y/2, y, 2*(num_y/2), gy);

    // 半分全列挙 part
    string mxs = "", mys = "";
    sort(gx.begin(), gx.end());
    sort(gy.begin(), gy.end());
    for(auto &&[cx, move]: sx) {
        auto itr = lower_bound(gx.begin(), gx.end(), P(cx, 0LL));
        if( itr == gx.end() || (*itr).first != cx ) continue;
        rep(j,num_x/2) mxs += ( move & (1LL << j) ? 'R' : 'L' );
        rep(j,(num_x-num_x/2)) mxs += ( (*itr).second & (1LL << j) ? 'L' : 'R' );
        break;
    }
    for(auto &&[cy, move]: sy) {
        auto itr = lower_bound(gy.begin(), gy.end(), P(cy, 0LL));
        if( itr == gy.end() || (*itr).first != cy ) continue;
        rep(j,num_y/2) mys += ( move & (1LL << j) ? 'U' : 'D' );
        rep(j,(num_y-num_y/2)) mys += ( (*itr).second & (1LL << j) ? 'D' : 'U' );
        break;
    }
    if( mxs == "" || mys == "" ) return cout << "No" << endl, 0;

    cout << "Yes" << endl;
    string move_ans = "";
    rep(i,n) move_ans += (i%2 == 0 ? mys[i/2] : mxs[i/2]);
    char now_d = 'R';
    rep(i,n) {
        if( now_d == 'R' ) cout << (move_ans[i] == 'U' ? 'L' : 'R');
        else if( now_d == 'L' ) cout << (move_ans[i] == 'U' ? 'R' : 'L');
        else if( now_d == 'U' ) cout << (move_ans[i] == 'R' ? 'R' : 'L');
        else cout << (move_ans[i] == 'R' ? 'L' : 'R');
        now_d = move_ans[i];
    }
    cout << endl;
    
    return 0;
}