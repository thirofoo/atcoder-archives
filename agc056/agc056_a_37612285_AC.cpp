/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc056/submissions/37612285
 * Submitted at: 2022-12-29 16:01:49
 * Problem URL: https://atcoder.jp/contests/agc056/tasks/agc056_a
 * Result: AC
 * Execution Time: 24 ms
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

// 埋め込み
vector<vector<string>> hard = {
    {
        "###...",
        "...###",
        "###...",
        "...###",
        "###...",
        "...###",
    },
    {
        "###....",
        "...###.",
        ".###...",
        "#....##",
        "..###..",
        "##....#",
        "....###",
    },
    {
        "###.....",
        "#.....##",
        "...###..",
        ".##....#",
        "##....#.",
        "...#.##.",
        "....##.#",
        "..###...",
    },
    {
        "#.#.#....",
        ".#.#.#...",
        "...###...",
        "###......",
        "...###...",
        "###......",
        "......###",
        "......###",
        "......###",
    },
    {
        "#.#.#.....",
        ".#.#.#....",
        "...###....",
        "###.......",
        "...###....",
        "###.......",
        ".......###",
        "......#.##",
        "......##.#",
        "......###.",
    },
    {
        "#.#.#......",
        ".#.#.#.....",
        "...###.....",
        "###........",
        "...###.....",
        "###........",
        "........###",
        "........###",
        "......##..#",
        "......##.#.",
        "......###..",
    },
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    // 失敗作
    // rep(i,(1LL << n*n)){
    //     bool f{true};
    //     // 行確認
    //     rep(j,n){
    //         ll tmp{0};
    //         rep(k,n)if(i & (1LL << (j*n+k)))tmp++;
    //         f &= (tmp == 3);
    //     }

    //     // 列確認
    //     rep(j,n){
    //         ll tmp{0};
    //         rep(k,n)if(i & (1LL << (k*n+j)))tmp++;
    //         f &= (tmp == 3);
    //     }
    //     if(!f)continue;

    //     // 連結確認
    //     vector visited(n,vector<bool>(n,false));
    //     queue<P> todo;
    //     rep(j,n*n)if(i & (1LL << j)){
    //         todo.push(P(j/n,j%n));
    //         break;
    //     }
    //     vector<int> dx = {0,-1,0,1};
    //     vector<int> dy = {-1,0,1,0};
    //     while(!todo.empty()){
    //         auto [x,y] = todo.front(); todo.pop();
    //         if(visited[x][y])continue;
    //         visited[x][y] = true;
    //         rep(j,4){
    //             ll nx = x+dx[j],ny = y+dy[j];
    //             if( 0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && (i & (1LL << (nx*n+ny))) )todo.push(P(nx,ny));
    //         }
    //     }
    //     rep(j,n)rep(k,n){
    //         if(i & (1LL << (j*n+k))){
    //             f &= visited[j][k];
    //         }
    //     }

    //     if(f){

    //         stack<ll> st;
    //         while(i){
    //             st.push(i%2);
    //             i >>= 1;
    //         }
    //         while(st.size() != n*n)st.push(0);
    //         ll now = 0;
    //         while(!st.empty()){
    //             cout << st.top();
    //             st.pop();
    //             if(now%n == n-1)print();
    //             now++;
    //         }
    //         return 0;
    //     }
    // }
    
    vector<vector<char>> ans(n,vector<char>(n,'.'));
    rep(i,6+n%6)rep(j,6+n%6)ans[i][j] = hard[n%6][i][j];
    ll now = 6+n%6;

    while(now < n){
        rep(i,6)rep(j,6)ans[i+now][j+now] = hard[0][i][j];
        now += 6;
    }
    rep(i,n){
        rep(j,n)cout << ans[i][j];
        print();
    }
    
    return 0;
}