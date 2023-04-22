/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc299/submissions/40869923
 * Submitted at: 2023-04-22 22:10:04
 * Problem URL: https://atcoder.jp/contests/abc299/tasks/abc299_e
 * Result: AC
 * Execution Time: 56 ms
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
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    ll k; input(k);
    vector<string> ans(k,"");
    rep(i,k)rep(j,n)ans[i] += "2";

    queue<P> todo;
    rep(i,k){
        ll p,d; input(p,d);
        p--;
        vector<bool> visited(n,false);
        todo.push(P(0,p));
        while(!todo.empty()){
            auto [nd,now] = todo.front(); todo.pop();
            if(visited[now])continue;
            if(nd == d){
                ans[i][now] = '1';
                continue;
            }
            ans[i][now] = '0';
            visited[now] = true;
            for(auto to:Graph[now]){
                todo.push(P(nd+1,to));
            }
        }
    }

    string answer = "";
    rep(i,n){
        bool f = true;
        rep(j,k)f &= (ans[j][i] == '1' || ans[j][i] == '2');
        answer += (f ? "1" : "0");
    }

    rep(i,k){
        bool f = false;
        rep(j,n)if(ans[i][j] == '1' && answer[j] == '1')f = true;
        if(!f)return print("No"),0;
    }
    print("Yes");
    print(answer);
    
    return 0;
}