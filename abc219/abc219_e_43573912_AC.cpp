/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc219/submissions/43573912
 * Submitted at: 2023-07-15 15:36:20
 * Problem URL: https://atcoder.jp/contests/abc219/tasks/abc219_e
 * Result: AC
 * Execution Time: 77 ms
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
    
    // ただの bit全探索 & bfs
    vector<vector<ll>> a(4,vector<ll>(4));
    vector<vector<bool>> visited;
    ll total_house = 0;
    rep(i,4)rep(j,4){
        input(a[i][j]);
        if( a[i][j] == 1 )total_house++;
    }

    ll ans = 0;
    queue<P> todo;
    rep(i,(1LL << 16)){
        if( i == 0 )continue;
        // 穴あきpaternを uf で求める！
        bool f = true;
        vector<vector<bool>> visited(6,vector<bool>(6,false));
        rep(j,4){
            rep(k,4){
                if( (i & (1LL << (j*4+k))) ) visited[j+1][k+1] = true;
                else if( a[j][k] ) f = false;
            }
        }
        if( !f ) continue;

        dsu uf(36);
        rep(j,6){
            rep(k,6){
                rep(d,4){
                    ll nx = j + dx[d], ny = k + dy[d];
                    if( outField(nx,ny,6,6) ) continue;
                    if( visited[j][k] == visited[nx][ny] ) uf.merge( j*6+k, nx*6+ny );
                }
            }
        }
        ans += (uf.groups().size() == 2);
    }
    print( ans );
    
    return 0;
}