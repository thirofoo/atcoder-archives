/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc292/submissions/39448843
 * Submitted at: 2023-03-04 23:52:26
 * Problem URL: https://atcoder.jp/contests/abc292/tasks/abc292_e
 * Result: AC
 * Execution Time: 52 ms
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
    
    ll n,m; input(n,m);
    vector Graph(n,vector<ll>{});
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
    }
    queue<ll> todo;
    ll ans = 0;
    rep(i,n){
        todo.push(i);
        vector<bool> visited(n,false);
        ll cnt = -1;
        while(!todo.empty()){
            ll now = todo.front(); todo.pop();
            if(visited[now])continue;
            visited[now] = true;
            cnt++;
            for(auto to:Graph[now]){
                if(visited[to])continue;
                todo.push(to);
            }
        }
        ans += cnt;
    }   
    ans -= m;
    print(ans);
    
    return 0;
}