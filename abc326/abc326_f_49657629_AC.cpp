/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/49657629
 * Submitted at: 2024-01-26 09:09:17
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_f
 * Result: AC
 * Execution Time: 1533 ms
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
    
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // i%2 == 0 ? y方向 : x方向 に任意に進めそう
    // ⇒ x, y それぞれ max 2^40 通りの進み方あり
    // ⇒ 半分全列挙？
    vector<pair<ll,string>> sx, gx, sy, gy;
    ll num_x = n/2, num_y = (n+1)/2;
    rep(i,(1LL << (num_x/2))) {
        ll now_x = 0;
        string move = "";
        rep(j,num_x/2) {
            now_x += a[2*j+1]*(i & (1LL << j) ? 1 : -1 );
            move += (i & (1LL << j) ? "R" : "L" );
        }
        sx.emplace_back(pair(now_x, move));
    }
    rep(i,(1LL << (num_y/2))) {
        ll now_y = 0;
        string move = "";
        rep(j,num_y/2) {
            now_y += a[2*j]*(i & (1LL << j) ? 1 : -1 );
            move += (i & (1LL << j) ? "U" : "D" );
        }
        sy.emplace_back(pair(now_y, move));
    }
    rep(i,(1LL << (num_x-num_x/2))) {
        ll now_x = x;
        string move = "";
        rep(j,(num_x-num_x/2)) {
            now_x += a[2*(num_x/2+j)+1]*(i & (1LL << j) ? 1 : -1 );
            move += (i & (1LL << j) ? "L" : "R" );
        }
        gx.emplace_back(pair(now_x, move));
    }
    rep(i,(1LL << (num_y-num_y/2))) {
        ll now_y = y;
        string move = "";
        rep(j,(num_y-num_y/2)) {
            now_y += a[2*(num_y/2+j)]*(i & (1LL << j) ? 1 : -1 );
            move += (i & (1LL << j) ? "D" : "U" );
        }
        gy.emplace_back(pair(now_y, move));
    }
    // 半分全列挙 part
    ll mx, my; string mxs, mys;
    bool xf = false, yf = false;
    sort(gx.begin(), gx.end());
    sort(gy.begin(), gy.end());
    for(auto [cx, move]: sx) {
        auto itr = lower_bound(gx.begin(), gx.end(), pair(cx,string("")));
        if( itr == gx.end() || (*itr).first != cx ) continue;
        xf = true, mx = cx, mxs = move + (*itr).second;
        break;
    }
    for(auto [cy, move]: sy) {
        auto itr = lower_bound(gy.begin(), gy.end(), pair(cy,string("")));
        if( itr == gy.end() || (*itr).first != cy ) continue;
        yf = true, my = cy, mys = move + (*itr).second;
        break;
    }

    if( !xf || !yf ) return cout << "No" << endl, 0;
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
    cerr << move_ans << endl;
    
    return 0;
}