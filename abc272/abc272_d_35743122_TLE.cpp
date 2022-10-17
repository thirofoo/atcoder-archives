/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc272/submissions/35743122
 * Submitted at: 2022-10-17 10:59:05
 * Problem URL: https://atcoder.jp/contests/abc272/tasks/abc272_d
 * Result: TLE
 * Execution Time: 2206 ms
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
    vector<vector<ll>> table(n,vector<ll>(n,-1));
    table[0][0] = 0;
    queue<T> todo;
    rep(i,n)rep(j,n)if(i*i+j*j == m)todo.push(T(1,i,j));
    while(!todo.empty()){
        auto [d,x,y] = todo.front(); todo.pop();
        if(table[x][y] != -1)continue;
        table[x][y] = d;
        rep(i,n)rep(j,n){
            if((i-x)*(i-x)+(j-y)*(j-y) == m){
                todo.push(T(d+1,i,j));
            }
        }
    }
    rep(i,n){
        rep(j,n)cout << table[i][j] << " ";
        print();
    }
    
    return 0;
}