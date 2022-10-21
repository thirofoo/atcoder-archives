/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc182/submissions/35837931
 * Submitted at: 2022-10-21 22:47:09
 * Problem URL: https://atcoder.jp/contests/abc182/tasks/abc182_e
 * Result: WA
 * Execution Time: 210 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w,n,m; input(h,w,n,m);
    vector<vector<bool>> field(h+2,vector<bool>(w+2,false)),cnt;
    cnt = field;
    rep(i,h+2){
        field[i][0] = true;
        field[i][w+1] = true;
    }
    rep(i,w+2){
        field[0][i] = true;
        field[h+1][i] = true;
    }
    queue<T> todo;
    rep(i,n){
        ll a,b; input(a,b);
        rep(j,4)todo.push(T(j,a,b));
    }
    rep(j,m){
        ll c,d; input(c,d);
        field[c][d] = true;
    }
    while(!todo.empty()){
        auto [dir,x,y] = todo.front(); todo.pop();
        if(field[x][y] || (cnt[x][y] && cnt[x+dx[dir]][y+dy[dir]]))continue;
        cnt[x][y] = true;
        todo.push(T(dir,x+dx[dir],y+dy[dir]));
    }
    ll ans = 0;
    rep(i,h+2)rep(j,w+2)if(cnt[i][j])ans++;
    print(ans);
    
    return 0;
}