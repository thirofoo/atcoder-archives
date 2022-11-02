/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc184/submissions/36156487
 * Submitted at: 2022-11-02 19:41:11
 * Problem URL: https://atcoder.jp/contests/abc184/tasks/abc184_e
 * Result: RE
 * Execution Time: 3403 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

// 右下左上の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

inline bool inGrid(int x,int y,int h,int w){
    if(0 <= x && x < h && 0 <= y && y < w)return true;
    else return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w; input(h,w);
    vector<string> field(h);
    rep(i,h)input(field[i]);

    ll sx,sy,gx,gy;
    vector<vector<P>> warp(26,vector<P>{});
    rep(i,h){
        rep(j,w){
            if(field[i][j] == 'S'){
                sx = i;
                sy = j;
                continue;
            }
            if(field[i][j] == 'G'){
                gx = i;
                gy = j;
                continue;
            }
            if('a' <= field[i][j] && field[i][j] <= 'z'){
                warp[field[i][j]-'a'].push_back(P(i,j));
            }
        }
    }

    queue<T> todo;
    vector<vector<ll>> visited(h,vector<ll>(w,0));
    todo.push(T(1,sx,sy));
    while(!todo.empty()){
        auto [c,x,y] = todo.front(); todo.pop();
        if(visited[x][y])continue;
        visited[x][y] = c;
        rep(i,4){
            ll nx = x+dx[i],ny = y+dy[i];
            if(inGrid(nx,ny,h,w) && field[nx][ny] != '#')todo.push(T(c+1,nx,ny));
        }
        if('a' <= field[x][y] && field[x][y] <= 'z'){
            for(auto [nx,ny]:warp[field[x][y]-'a']){
                todo.push(T(c+1,nx,ny));
            }
        }
    }
    print((visited[gx][gy] ? visited[gx][gy]-1 : -1));
    
    return 0;
}