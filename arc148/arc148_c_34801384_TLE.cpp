/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc148/submissions/34801384
 * Submitted at: 2022-09-11 22:58:26
 * Problem URL: https://atcoder.jp/contests/arc148/tasks/arc148_c
 * Result: TLE
 * Execution Time: 3309 ms
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
vector<ll> v,dp;
ll ans;
ll dfs(ll now,ll pre){
    for(auto to:Graph[now]){
        dp[now] += dfs(to,v[now]);
    }
    if(v[now] != pre)dp[now]++;
    return dp[now];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; input(n,q);
    Graph.assign(n,{});
    rep(i,n-1){
        ll p; input(p); p--;
        Graph[p].push_back(i+1);
    }
    while(q--){
        ll m; input(m);
        ans = -1;
        v.assign(n,0);
        dp.assign(n,0);
        rep(i,m){
            ll tmp; input(tmp); tmp--;
            v[tmp] = 1;
        }
        print(dfs(0,0));
        // rep(i,n)cout << dp[i] << " ";
        // print();
    }
    
    return 0;
}