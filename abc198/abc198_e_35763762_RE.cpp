/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc198/submissions/35763762
 * Submitted at: 2022-10-18 13:10:54
 * Problem URL: https://atcoder.jp/contests/abc198/tasks/abc198_e
 * Result: RE
 * Execution Time: 106 ms
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

set<ll> ans;
vector<ll> color;
vector<bool> ng;
void dfs(int now,int pre,vector<vector<ll>> &Graph){
    bool f = false;
    if(!ng[color[now]]){
        ng[color[now]] = true;
        ans.insert(now);
        f = true;
    }
    for(auto to:Graph[now]){
        if(to == pre)continue;
        dfs(to,now,Graph);
    }
    if(f)ng[color[now]] = false;
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<vector<ll>> Graph(n);
    color.assign(n,0);
    rep(i,n)input(color[i]);
    rep(i,n-1){
        ll a,b; input(a,b);
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    ng.assign(n,false);
    dfs(0,-1,Graph);
    for(auto node:ans)print(node+1);
    
    return 0;
}