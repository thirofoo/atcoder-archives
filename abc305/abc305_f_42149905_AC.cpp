/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc305/submissions/42149905
 * Submitted at: 2023-06-10 21:54:36
 * Problem URL: https://atcoder.jp/contests/abc305/tasks/abc305_f
 * Result: AC
 * Execution Time: 17 ms
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
    vector<bool> visited(n,false), already(n,false);
    vector<vector<ll>> Graph(n);
    stack<ll> st;

    ll now = 0;
    already[now] = true;
    visited[now] = true;

    while(true){
        // 再起っぽく
        ll k; input(k);
        rep(i,k){
            ll v; input(v);
            v--;
            if(already[v])continue;
            already[v] = true;
            Graph[v].push_back(now);
            Graph[now].push_back(v);
        }
        bool f = false;
        for(auto to:Graph[now]){
            if(visited[to])continue;
            st.push(now);
            visited[to] = true;
            now = to;
            f = true;
            break;
        }
        if(!f){
            now = st.top();
            st.pop();
        }

        print(now+1);
        cout << flush;
        
        if(now == n-1){
            string ok; input(ok);
            return 0;
        }
    }
    
    return 0;
}