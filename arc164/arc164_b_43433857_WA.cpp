/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc164/submissions/43433857
 * Submitted at: 2023-07-09 22:48:33
 * Problem URL: https://atcoder.jp/contests/arc164/tasks/arc164_b
 * Result: WA
 * Execution Time: 95 ms
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
    vector<vector<ll>> Graph(n);
    rep(i,m){
        ll a, b; input(a,b);
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    vector<ll> c(n);
    rep(i,n) input(c[i]);

    queue<ll> todo;
    vector<bool> visited(n,0);
    rep(i,n){
        if( visited[i] )continue;
        todo.push(i);
        while(!todo.empty()){
            ll now = todo.front(); todo.pop();
            if( visited[now] )continue;
            visited[now] = true;
            for(auto to:Graph[now]){
                if( visited[to] && c[now] == c[to] ){
                    print("Yes");
                    return 0;
                }
                if( !visited[to] && c[now] != c[to] ) todo.push(to);
            }
        }
    }
    print("No");
    
    return 0;
}