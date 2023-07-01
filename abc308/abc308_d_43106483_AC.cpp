/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc308/submissions/43106483
 * Submitted at: 2023-07-01 21:17:22
 * Problem URL: https://atcoder.jp/contests/abc308/tasks/abc308_d
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
    
    string snuke = "snuke";
    ll h,w; input(h,w);
    vector<string> s(h);
    rep(i,h)input(s[i]);

    if(s[0][0] != 's'){
        print("No");
        return 0;
    }
    queue<T> todo;
    todo.push(T(0,0,0));
    vector<vector<bool>> visited(h,vector<bool>(w,false));
    while(!todo.empty()){
        auto [x,y,idx] = todo.front(); todo.pop();
        if( visited[x][y] )continue;
        visited[x][y] = true;
        rep(i,4){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if( outField(nx,ny,h,w) || visited[nx][ny] || s[nx][ny] != snuke[(idx+1)%5])continue;
            todo.push(T(nx,ny,(idx+1)%5));
        }
    }
    print( (visited[h-1][w-1] ? "Yes" : "No") );
    
    return 0;
}