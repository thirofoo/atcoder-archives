/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/49975024
 * Submitted at: 2024-02-03 23:39:26
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_d
 * Result: TLE
 * Execution Time: 4672 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll, ll, ll>;
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
    
    ll n; cin >> n;
    vector<string> s(n);
    vector<P> player;
    rep(i,n) {
        cin >> s[i];
        rep(j,n) if( s[i][j] == 'P' ) player.push_back(P(i,j));
    }
    queue<T> todo;
    todo.push(T(0,player[0].first, player[0].second, player[1].first, player[1].second));
    vector vis(n, vector(n, vector(n, vector(n, LLONG_MAX))));
    while(!todo.empty()) {
        auto [dis,x1,y1,x2,y2] = todo.front(); todo.pop();
        if( vis[x1][y1][x2][y2] <= dis ) continue;
        vis[x1][y1][x2][y2] = dis;
        rep(i,4) {
            ll px1 = -1, py1 = -1, px2 = -1, py2 = -1, cnt = 0;
            ll now_x1 = x1, now_y1 = y1, now_x2 = x2, now_y2 = y2;
            while( px1 != now_x1 || py1 != now_y1 || px2 != now_x2 || py2 != now_y2 ) {
                ll nx1 = now_x1 + dx[i], ny1 = now_y1 + dy[i];
                ll nx2 = now_x2 + dx[i], ny2 = now_y2 + dy[i];
                px1 = now_x1, py1 = now_y1;
                px2 = now_x2, py2 = now_y2;

                if( !outField(nx1,ny1,n,n) && s[nx1][ny1] != '#' ) now_x1 = nx1, now_y1 = ny1;
                if( !outField(nx2,ny2,n,n) && s[nx2][ny2] != '#' ) now_x2 = nx2, now_y2 = ny2;
                cnt++;
                if( vis[now_x1][now_y1][now_x2][now_y2] <= dis+cnt ) continue;
                todo.push(T(dis+cnt,now_x1,now_y1,now_x2,now_y2));
            }
        }
    }
    ll ans = LLONG_MAX;
    rep(i,n) rep(j,n) rep(k,n) rep(l,n) if( i == k && j == l ) ans = min(ans, vis[i][j][k][l]);
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    
    return 0;
}