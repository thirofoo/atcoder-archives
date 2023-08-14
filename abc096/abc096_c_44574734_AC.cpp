/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc096/submissions/44574734
 * Submitted at: 2023-08-14 09:28:04
 * Problem URL: https://atcoder.jp/contests/abc096/tasks/abc096_c
 * Result: AC
 * Execution Time: 7 ms
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
    ll h,w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<bool>> visited(h,vector<bool>(w,false));
    queue<P> todo;
    rep(i,h) {
        rep(j,w) {
            if( visited[i][j] || s[i][j] == '.' ) continue;
            ll cnt = 0;
            todo.push(P(i,j));
            while( !todo.empty() ) {
                auto [x,y] = todo.front(); todo.pop();
                if( visited[x][y] ) continue;
                visited[x][y] = true;
                cnt++;
                rep(d,4) {
                    ll nx = x + dx[d], ny = y + dy[d];
                    if( outField(nx,ny,h,w) || visited[nx][ny] || s[nx][ny] == '.' ) continue;
                    todo.push(P(nx,ny));
                }
            }
            if( cnt == 1 ) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}