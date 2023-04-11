/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc202/submissions/40531974
 * Submitted at: 2023-04-11 15:55:34
 * Problem URL: https://atcoder.jp/contests/abc202/tasks/abc202_e
 * Result: AC
 * Execution Time: 126 ms
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

vector<vector<ll>> Graph;
vector<ll> in,out,d;
vector<vector<ll>> d_turn;
ll turn = 0;
void dfs(ll now, ll pre, ll depth){
    d[now] = depth;
    in[now] = turn;
    d_turn[depth].push_back(turn);
    turn++;
    for(ll to:Graph[now]){
        if(pre == to)continue;
        dfs(to,now,depth+1);
    }
    out[now] = turn;
    turn++;
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    Graph.assign(n,vector<ll>{});
    d.assign(n,0);
    in.assign(n,0);
    out.assign(n,0);
    d_turn.assign(n,{});
    rep(i,n-1){
        ll p; input(p);
        Graph[i+1].push_back(p-1);
        Graph[p-1].push_back(i+1);
    }

    dfs(0,-1,0);
    rep(i,n)sort(d_turn[i].begin(),d_turn[i].end());

    ll q; input(q);
    while(q--){
        ll u,dd; input(u,dd);
        u--;
        auto i1 = lower_bound(d_turn[dd].begin(),d_turn[dd].end(),in[u]);
        auto i2 = lower_bound(d_turn[dd].begin(),d_turn[dd].end(),out[u]);
        print(i2-i1);
    }
    
    return 0;
}   