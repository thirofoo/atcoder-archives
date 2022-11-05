/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc276/submissions/36253948
 * Submitted at: 2022-11-05 22:14:20
 * Problem URL: https://atcoder.jp/contests/abc276/tasks/abc276_e
 * Result: AC
 * Execution Time: 36 ms
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

inline bool inGrid(int x,int y,int h,int w){
    if(0 <= x && x < h && 0 <= y && y < w)return true;
    else return false;
}

// 右下左上の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};
vector<P> p = {P(0,1),P(0,2),P(0,3),P(1,2),P(1,3),P(2,3),};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w; input(h,w);
    vector<string> field(h);
    rep(i,h)input(field[i]);
    int sx,sy;
    rep(i,h)rep(j,w){
        if(field[i][j] == 'S'){
            sx = i;
            sy = j;
            field[i][j] = '#';
        }
    }
    queue<T> todo;
    for(auto [sd1,sd2]:p){
        vector<vector<int>> visited(h,vector<int>(w,0));
        ll sx1 = sx+dx[sd1],sy1 = sy+dy[sd1];
        if(!inGrid(sx1,sy1,h,w) || field[sx1][sy1] == '#')continue;
        ll sx2 = sx+dx[sd2],sy2 = sy+dy[sd2];
        if(!inGrid(sx2,sy2,h,w) || field[sx2][sy2] == '#')continue;
        todo.push(T(1,sx1,sy1));
        todo.push(T(2,sx2,sy2));
        while(!todo.empty()){
            auto [c,x,y] = todo.front(); todo.pop();
            if(visited[x][y] != 0 && visited[x][y] != c)return print("Yes"),0;
            if(visited[x][y] == c)continue;
            visited[x][y] = c;
            rep(i,4){
                ll nx = x+dx[i],ny = y+dy[i];
                if(!inGrid(nx,ny,h,w) || field[nx][ny] == '#' || visited[nx][ny] == c)continue;
                todo.push(T(c,nx,ny));
            }
        }
    }
    print("No");
    
    return 0;
}