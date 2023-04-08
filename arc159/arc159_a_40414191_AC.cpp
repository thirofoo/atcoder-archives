/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc159/submissions/40414191
 * Submitted at: 2023-04-08 21:23:23
 * Problem URL: https://atcoder.jp/contests/arc159/tasks/arc159_a
 * Result: AC
 * Execution Time: 428 ms
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
    
    ll n,k; input(n,k);
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n)input(a[i][j]);

    ll q; input(q);
    queue<P> todo;

    while(q--){
        ll s,t; input(s,t);
        s--; t--;
        ll ans = LLONG_MAX;
        rep(i,n){
            ll cand = 0;
            if(!a[s%n][i])continue;
            vector<ll> visited(n,LLONG_MAX);
            todo.push(P(i,1));
            while(!todo.empty()){
                auto [now,d] = todo.front(); todo.pop();
                if(visited[now] != LLONG_MAX)continue;
                visited[now] = d;
                rep(j,n){
                    if(visited[j] != LLONG_MAX || !a[now][j])continue;
                    todo.push(P(j,d+1));
                }
            }
            ans = min(ans,visited[t%n]);
        }
        print( (ans == LLONG_MAX ? -1 : ans) );
    }
    
    return 0;
}