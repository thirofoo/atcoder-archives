/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc176/submissions/36171209
 * Submitted at: 2022-11-03 15:18:25
 * Problem URL: https://atcoder.jp/contests/abc176/tasks/abc176_d
 * Result: AC
 * Execution Time: 1017 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w,cx,cy,ex,ey; input(h,w,cx,cy,ex,ey);
    cx--; cy--; ex--; ey--;
    vector<string> field(h);
    rep(i,h)input(field[i]);

    vector<vector<ll>> visited(h,vector<ll>(w,LLONG_MAX));
    priority_queue<T,vector<T>,greater<T>> todo;
    todo.push(T(0,cx,cy));
    while(!todo.empty()){
        auto [c,x,y] = todo.top(); todo.pop();
        if(visited[x][y] <= c)continue;
        visited[x][y] = c;
        for(int dx=-2;dx<=2;dx++){
            if(x+dx < 0 || h <= x+dx)continue;
            for(int dy=-2;dy<=2;dy++){
                if(y+dy < 0 || w <= y+dy)continue;

                if(field[x+dx][y+dy] == '#')continue;
                if((dx == 0 && abs(dy) == 1) || (dy == 0 && abs(dx) == 1)){
                    todo.push(T(c,x+dx,y+dy));
                }
                else todo.push(T(c+1,x+dx,y+dy));
            }
        }
    }
    print(visited[ex][ey] == LLONG_MAX ? -1 : visited[ex][ey]);
    
    return 0;
}