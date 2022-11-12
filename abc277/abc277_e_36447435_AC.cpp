/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc277/submissions/36447435
 * Submitted at: 2022-11-12 22:35:18
 * Problem URL: https://atcoder.jp/contests/abc277/tasks/abc277_e
 * Result: AC
 * Execution Time: 886 ms
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
    
    ll n,m,k; input(n,m,k);
    set<int> st;
    map<P,set<int>> a,b;
    vector<vector<ll>> Graph(n);
    rep(i,m){
        ll u,v,sw; input(u,v,sw);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        a[P(u,v)].insert(sw);
        a[P(v,u)].insert(sw);
    }
    rep(i,k){
        int s; input(s); s--;
        st.insert(s);
    }
    vector<vector<ll>> dp(2,vector<ll>(n,LLONG_MAX));
    deque<T> todo;
    // T(now,onoff,cost)
    todo.push_front(T(0,0,0));
    while(!todo.empty()){
        auto [now,f,cost] = todo.front(); todo.pop_front();
        if(dp[f][now] != LLONG_MAX)continue;
        dp[f][now] = cost;

        if(st.count(now))todo.push_front(T(now,f^1,cost));
        for(auto next:Graph[now]){
            for(auto ok:a[P(now,next)]){
                if(ok^f){
                    todo.push_back(T(next,f,cost+1));
                }
            }
        }
    }
    print((dp[0][n-1] == LLONG_MAX && dp[1][n-1] == LLONG_MAX ? -1 : min(dp[0][n-1],dp[1][n-1])));

    return 0;
}