/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc334/submissions/48758240
 * Submitted at: 2023-12-23 21:26:15
 * Problem URL: https://atcoder.jp/contests/abc334/tasks/abc334_e
 * Result: AC
 * Execution Time: 85 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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
    vector<vector<ll>> vis(h, vector<ll>(w,0));
    queue<P> todo;
    mint group = 0, num = 0;
    rep(i,h) rep(j,w) {
        if( vis[i][j] || s[i][j] == '.' ) continue;
        todo.push(P(i,j));
        group++;
        while( !todo.empty() ) {
            auto [x,y] = todo.front(); todo.pop();
            if( vis[x][y] ) continue;
            vis[x][y] = group.val();
            num++;
            rep(d,4) {
                ll nx = x+dx[d], ny = y+dy[d];
                if( outField(nx,ny,h,w) || s[nx][ny] == '.' ) continue;
                todo.push(P(nx,ny));
            }
        }
    }
    num = h*w - num;
    mint ans = 0;
    rep(i,h) rep(j,w) {
        if( s[i][j] == '.' ) {
            mint cand = group+1;
            set<ll> st;
            st.insert(0);
            rep(d,4) {
                ll nx = i+dx[d], ny = j+dy[d];
                if( outField(nx,ny,h,w) ) continue;
                st.insert(vis[nx][ny]);
            }
            ans += cand-(st.size()-1);
            // cerr << ans.val() << endl;
        }
    }
    // cerr << ans.val() << " " << num.val() << " " << group.val() << endl;
    cout << (ans/num).val() << endl;
    
    return 0;
}