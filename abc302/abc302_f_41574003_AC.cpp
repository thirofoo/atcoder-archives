/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc302/submissions/41574003
 * Submitted at: 2023-05-20 22:23:24
 * Problem URL: https://atcoder.jp/contests/abc302/tasks/abc302_f
 * Result: AC
 * Execution Time: 392 ms
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
    vector<set<ll>> v(m),g(n);
    rep(i,n){
        ll a; input(a);
        rep(j,a){
            ll b; input(b);
            b--;
            v[b].insert(i);
            g[i].insert(b);
        }
    }
    vector<bool> already(n,false);
    queue<P> todo;
    for(auto ele:v[0]){
        todo.push(P(ele,0));
        already[ele] = true;
    }
    while(!todo.empty()){
        auto [now,c] = todo.front(); todo.pop();
        if(g[now].count(m-1)){
            print(c);
            return 0;
        }
        for(auto ele:g[now]){
            for(auto to:v[ele]){
                if(already[to])continue;
                already[to] = true;
                todo.push(P(to,c+1));
            }
        }
    }
    print(-1);
    
    return 0;
}