/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc269/submissions/34937198
 * Submitted at: 2022-09-17 21:34:49
 * Problem URL: https://atcoder.jp/contests/abc269/tasks/abc269_d
 * Result: AC
 * Execution Time: 10 ms
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

vector<int> dx = {-1,-1,0,0,1,1};
vector<int> dy = {-1,0,-1,1,0,1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<vector<bool>> field(3000,vector<bool>(3000,false)),visited(3000,vector<bool>(3000,false));
    queue<P> todo,todo2;
    rep(i,n){
        ll x,y; input(x,y);
        x += 1000; y += 1000;
        field[x][y] = true;
        todo.push(P(x,y));
    }

    ll ans = 0;
    while(!todo.empty()){
        auto [x,y] = todo.front(); todo.pop();
        if(visited[x][y])continue;
        todo2.push(P(x,y));
        while(!todo2.empty()){
            auto [nx,ny] = todo2.front(); todo2.pop();
            if(visited[nx][ny])continue;
            visited[nx][ny] = true;
            rep(i,6){
                ll tox = nx + dx[i],toy = ny + dy[i];
                if(0 <= tox && tox <= 2005 && 0 <= toy && toy <= 2005  && field[tox][toy] && !visited[tox][toy]){
                    todo2.push(P(tox,toy));
                }
            }
        }
        ans++;
    }
    print(ans);
    
    return 0;
}