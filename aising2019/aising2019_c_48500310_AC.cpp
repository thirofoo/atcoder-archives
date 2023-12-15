/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/aising2019/submissions/48500310
 * Submitted at: 2023-12-15 10:19:08
 * Problem URL: https://atcoder.jp/contests/aising2019/tasks/aising2019_c
 * Result: AC
 * Execution Time: 13 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

// 左上右下の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

inline bool outField(int x,int y,int h,int w){
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    dsu uf(h*w);
    rep(i,h) rep(j,w) {
        rep(d,4) {
            ll nx = i+dx[d], ny = j+dy[d];
            if( outField(nx,ny,h,w) || s[i][j] == s[nx][ny] ) continue;
            uf.merge(i*w+j, nx*w+ny);
        }
    }
    vector g = uf.groups();
    ll ans = 0;
    for(auto v:g) {
        ll w_cnt = 0;
        for(auto ele:v) w_cnt += (s[ele/w][ele%w] == '.');
        ans += w_cnt*(v.size()-w_cnt);
    }
    cout << ans << '\n';
    
    return 0;
}