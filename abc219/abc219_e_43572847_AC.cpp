/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc219/submissions/43572847
 * Submitted at: 2023-07-15 14:49:19
 * Problem URL: https://atcoder.jp/contests/abc219/tasks/abc219_e
 * Result: AC
 * Execution Time: 29 ms
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

    // oの字のように2重に囲われているパターンはng
    // 0110 0100 0010 0000 0000 0110 0000 0100 0010 0110 0110 0100 0010
    // 1001 1010 0101 0100 0010 1001 0110 1010 0101 1001 1001 1010 0101
    // 1001 0100 0010 1010 0101 0110 1001 1010 0101 1010 0101 1001 1001
    // 0110 0000 0000 0100 0010 0000 0110 0100 0010 0100 0010 0110 0110

    vector<ll> ng1 = { 27030,19008,9504,1188,594,26976,1686,19108,9554,27044,26962,19094,9622 };
    vector<ll> ng2 = { 2016,1024,512,64,32,1536,96,1088,544,1600,1568,1120,608 };

    ll ans = 0;
    queue<P> todo;
    rep(i,(1LL << 16)){
        if( i == 0 )continue;
        bool ngf = false;
        rep(j,ng1.size()){
            if( (ng1[j] & i) == ng1[j] && (ng2[j] & i) != ng2[j] ){
                ngf = true;
                break;
            }
        }
        if( ngf )continue;

        ll popcnt = __builtin_popcount(i);
        visited.assign(4,vector<bool>(4,false));
        rep(j,16){
            if( i & (1LL << j) ){
                todo.push(P(j/4,j%4));
                break;
            }
        }
        ll vis_cnt = 0, house_cnt = 0;
        while(!todo.empty()){
            auto [x,y] = todo.front(); todo.pop();
            if( visited[x][y] )continue;
            visited[x][y] = true;
            vis_cnt++;
            if( a[x][y] == 1 )house_cnt++;
            rep(j,4){
                ll nx = x + dx[j], ny = y + dy[j];
                if( outField(nx,ny,4,4) || visited[nx][ny] || !(i & (1LL << (nx*4+ny))) )continue;
                todo.push(P(nx,ny));
            }
        }
        
        if( house_cnt == total_house && vis_cnt == popcnt ){
            ans++;
            // rep(j,4){
            //     rep(k,4){
            //         cout << ( (i & (1LL << (j*4+k))) ? "#" : "." );
            //     }
            //     print();
            // }
            // print();
        }
    }
    print( ans );
    
    return 0;
}