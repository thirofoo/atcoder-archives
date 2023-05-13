/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc301/submissions/41397577
 * Submitted at: 2023-05-14 00:11:05
 * Problem URL: https://atcoder.jp/contests/abc301/tasks/abc301_e
 * Result: AC
 * Execution Time: 663 ms
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
ll h,w,t;

ll outField(ll x, ll y){
    if(x < 0 || x >= h || y < 0 || y >= w)return 1;
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(h,w,t);
    vector<string> field(h);
    rep(i,h)input(field[i]);

    ll sx,sy,gx,gy,cnt = 0;
    map<P,ll> idx;
    vector<P> o;
    rep(i,h)rep(j,w){
        if(field[i][j] == 'o'){
            o.push_back(P(i,j));
            idx[P(i,j)] = cnt;
            cnt++;
        }
        else if(field[i][j] == 'S'){
            o.push_back(P(i,j));
            sx = i; sy = j;
            idx[P(i,j)] = cnt;
            cnt++;
        }
        else if(field[i][j] == 'G'){
            o.push_back(P(i,j));
            gx = i; gy = j;
            idx[P(i,j)] = cnt;
            cnt++;
        }
    }

    vector<vector<P>> Graph(o.size());
    queue<T> todo;
    rep(i,o.size()){
        vector<vector<ll>> visited(h,vector<ll>(w,LLONG_MAX));
        auto [lx,ly] = o[i];
        todo.push(T(lx,ly,0));
        while(!todo.empty()){
            auto [x,y,c] = todo.front(); todo.pop();
            if(visited[x][y] <= c)continue;
            visited[x][y] = c;
            if(field[x][y] == 'o' || field[x][y] == 'S' || field[x][y] == 'G'){
                Graph[i].push_back(P(idx[P(x,y)],c));
            }

            rep(j,4){
                ll nx = x + dx[j];
                ll ny = y + dy[j];
                if(outField(nx,ny) || visited[nx][ny] <= c+1)continue;
                if(field[nx][ny] == '#')continue;
                todo.push(T(nx,ny,c+1));
            }
        }
    }

    // rep(i,o.size())Graph[i].erase(unique(Graph[i].begin(), Graph[i].end()), Graph[i].end());

    ll ans = -1;
    vector<vector<ll>> dp((1LL << o.size()),vector<ll>(o.size(),LLONG_MAX));
    dp[(1LL << idx[P(sx,sy)])][idx[P(sx,sy)]] = 0;
    rep(i,(1LL << o.size())){
        rep(j,o.size()){
            if(dp[i][j] == LLONG_MAX)continue;
            for(auto [k,cost]:Graph[j]){
                if(i & (1LL << k))continue;
                dp[i | (1LL << k)][k] = min(dp[i | (1LL << k)][k],dp[i][j] + cost);
            }
        }
    }

    rep(i,(1LL << o.size())){
        if(dp[i][idx[P(gx,gy)]] <= t){
            ll cand = 0;
            rep(j,o.size())if(i & (1LL << j))cand++;
            ans = max(cand-2,ans);
        }
    }
    print(ans);
    
    return 0;
}