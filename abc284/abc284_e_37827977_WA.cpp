/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc284/submissions/37827977
 * Submitted at: 2023-01-07 21:48:20
 * Problem URL: https://atcoder.jp/contests/abc284/tasks/abc284_e
 * Result: WA
 * Execution Time: 2272 ms
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
typedef tuple<ll, set<ll>> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    vector<vector<ll>> Graph;
    Graph.assign(n,vector<ll>{});
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    ll ans = 0;
    queue<T> todo;
    todo.push(T(0,{}));
    while(!todo.empty()){
        if(ans >= 1000000)break;
        ans++;
        auto [now,st] = todo.front(); todo.pop();
        st.insert(now);
        while(Graph[now].size() == 2){
            bool f = true;
            for(auto to:Graph[now]){
                if(st.count(to))continue;
                st.insert(to);
                now = to;
                ans++;
                f = false;
            }
            if(f)break;
        }
        for(auto to:Graph[now]){
            if(st.count(to))continue;
            todo.push(T(to,st));
        }
    }
    print(min(ans,(ll)1000000));
    
    return 0;
}