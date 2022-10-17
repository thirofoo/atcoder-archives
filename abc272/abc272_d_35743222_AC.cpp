/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc272/submissions/35743222
 * Submitted at: 2022-10-17 11:06:45
 * Problem URL: https://atcoder.jp/contests/abc272/tasks/abc272_d
 * Result: AC
 * Execution Time: 149 ms
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

vector<int> dx = {1,1,-1,-1};
vector<int> dy = {1,-1,-1,1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    set<P> st;
    vector<vector<ll>> table(n,vector<ll>(n,-1));
    table[0][0] = 0;
    queue<T> todo;
    rep(i,n)rep(j,n){
        if(i*i+j*j == m){
            todo.push(T(1,i,j));
            rep(k,4)st.insert(P(dx[k]*i,dy[k]*j));
            rep(k,4)st.insert(P(dy[k]*j,dx[k]*i));
        }
    }
    while(!todo.empty()){
        auto [d,x,y] = todo.front(); todo.pop();
        if(table[x][y] != -1)continue;
        table[x][y] = d;
        for(auto [i,j]:st){
            if(0 <= x+i && x+i < n && 0 <= y+j && y+j < n){
                todo.push(T(d+1,x+i,y+j));
            }
        }
    }
    rep(i,n){
        rep(j,n)cout << table[i][j] << " ";
        print();
    }
    
    return 0;
}