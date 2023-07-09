/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc164/submissions/43432335
 * Submitted at: 2023-07-09 22:34:48
 * Problem URL: https://atcoder.jp/contests/arc164/tasks/arc164_b
 * Result: WA
 * Execution Time: 101 ms
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
    
    // 黒黒 || 白白 のあるループが存在 → OK
    // それ以外 : 無理

    ll n,m; input(n,m);
    vector<vector<ll>> Graph(n);
    vector<ll> dig(n,0);
    rep(i,m){
        ll a, b; input(a,b);
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        dig[a]++;
        dig[b]++;
    }
    vector<ll> c(n);
    rep(i,n) input(c[i]);

    queue<ll> todo;
    rep(i,n)if(dig[i] == 1)todo.push(i);
    vector<bool> visited(n,false);
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        if( visited[now] ) continue;
        visited[now] = true;
        dig[now]--;
        for(auto to:Graph[now]){
            if( dig[to] == 2 ){
                dig[to]--;
                todo.push(to);
            }
        }
    }
    rep(i,n){
        for(auto j:Graph[i]){
            if( visited[i] || visited[j] )continue;
            if( c[i] == c[j] ){
                print("Yes");
                return 0;
            }
        }
    }
    print("No");
    
    return 0;
}