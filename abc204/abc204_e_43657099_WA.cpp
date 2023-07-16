/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc204/submissions/43657099
 * Submitted at: 2023-07-16 10:47:55
 * Problem URL: https://atcoder.jp/contests/abc204/tasks/abc204_e
 * Result: WA
 * Execution Time: 92 ms
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
    vector<vector<T>> Graph(n);
    rep(i,m){
        ll a,b,c,d; input(a,b,c,d);
        a--; b--;
        Graph[a].push_back(T(b,c,d));
        Graph[b].push_back(T(a,c,d));
    }

    priority_queue<P,vector<P>,greater<P>> todo;
    vector<ll> visited(n,1e16);
    todo.push(P(0,0));
    while( !todo.empty() ){
        auto [time, now] = todo.top(); todo.pop();
        if( visited[now] <= time ) continue;
        visited[now] = time;
        for(auto &&[to,nc,nd]:Graph[now]){
            // 相加相乗より、t = √d - 1 で最小を取る
            ll rest = time + ( nc + nd / (time+1) );
            if( time <= sqrt(nd) - 1 ){
                for(ll nt=sqrt(nd)-1;nt<sqrt(nd)+1;nt++){
                    if( nt <= 0 ) continue;
                    rest = nt + ( nc - 1 + nd / nt );
                    if( visited[to] <= rest ) continue;
                    todo.push(P(rest,to));
                }
            }
            else{
                if( rest < 0 || visited[to] >= rest ) continue;
                todo.push(P(rest,to));
            }
        }
    }
    print( (visited[n-1] == 1e16 ? -1: visited[n-1]) );
    
    return 0;
}