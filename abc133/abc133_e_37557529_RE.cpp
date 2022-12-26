/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc133/submissions/37557529
 * Submitted at: 2022-12-26 14:54:51
 * Problem URL: https://atcoder.jp/contests/abc133/tasks/abc133_e
 * Result: RE
 * Execution Time: 141 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll n,k;
mint ans;
vector<vector<ll>> Graph;
vector<mint> kaizyo;

mint nPr(ll n,ll r){
    return kaizyo[n] / kaizyo[n-r];
}

void dfs(ll now,ll pre,ll d){
    ans *= nPr( k-min(2LL,d) , Graph[now].size()-(d == 1 ? 0 : 1) );
    for(auto to:Graph[now]){
        if(to == pre)continue;
        dfs(to,now,d+1);
    }
}   

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n,k);
    Graph.assign(n,vector<ll>{});
    rep(i,n-1){
        ll a,b; input(a,b); a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    kaizyo.assign(k+1,1);
    for(int i=1;i<=k;i++)kaizyo[i] = kaizyo[i-1]*i;
    ans = k;
    dfs(0,-1,1);
    print(ans.val());
    
    return 0;
}