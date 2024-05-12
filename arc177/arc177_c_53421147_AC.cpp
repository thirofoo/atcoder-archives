/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc177/submissions/53421147
 * Submitted at: 2024-05-12 21:35:32
 * Problem URL: https://atcoder.jp/contests/arc177/tasks/arc177_c
 * Result: AC
 * Execution Time: 28 ms
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

// right | down | left | up
#define DIR_NUM 4
vector<int> dx = { 0, 1, 0,-1};
vector<int> dy = { 1, 0,-1, 0};

inline bool outField(int x,int y,int h,int w) {
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<string> c(n);
    rep(i,n) cin >> c[i];

    vector<vector<ll>> red(n,vector<ll>(n,INF)), blue(n,vector<ll>(n,INF));
    deque<T> q;
    q.push_back({0, 0, 0});
    while( !q.empty() ) {
        auto [x, y, d] = q.front(); q.pop_front();
        if( red[x][y] <= d ) continue;
        red[x][y] = d;
        rep(dir, DIR_NUM) {
            ll nx = x + dx[dir];
            ll ny = y + dy[dir];
            if( outField(nx, ny, n, n) ) continue;
            if( c[nx][ny] == 'R' && red[nx][ny] > d ) q.push_front({nx, ny, d});
            else if( c[nx][ny] == 'B' && red[nx][ny] > d+1 ) q.push_back({nx, ny, d+1});
        }
    }
    q.push_back({0, n-1, 0});
    while( !q.empty() ) {
        auto [x, y, d] = q.front(); q.pop_front();
        if( blue[x][y] != INF ) continue;
        blue[x][y] = d;
        rep(dir, DIR_NUM) {
            ll nx = x + dx[dir];
            ll ny = y + dy[dir];
            if( outField(nx, ny, n, n) ) continue;
            if( c[nx][ny] == 'B' && blue[nx][ny] > d ) q.push_front({nx, ny, d});
            else if( c[nx][ny] == 'R' && blue[nx][ny] > d+1 ) q.push_back({nx, ny, d+1});
        }
    }
    cout << red[n-1][n-1] + blue[n-1][0] << endl;
    
    return 0;
}