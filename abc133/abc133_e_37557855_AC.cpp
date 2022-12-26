/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc133/submissions/37557855
 * Submitted at: 2022-12-26 15:15:32
 * Problem URL: https://atcoder.jp/contests/abc133/tasks/abc133_e
 * Result: AC
 * Execution Time: 58 ms
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
vector<vector<ll>> Graph;
mint dfs(ll now,ll pre,ll rest){
    mint res = rest;
    mint used = 1;
    for(auto to:Graph[now]){
        if(to == pre)continue;
        res *= dfs(to,now,k-used.val()-(pre != -1));
        used++;
        // usedをインクリメントしてやってく
        // => 駄目なパターンも0でやってくれる
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説解法
    // 数学解法でなくても木dpで解ける
    input(n,k);
    Graph.assign(n,vector<ll>{});
    rep(i,n-1){
        ll a,b; input(a,b); a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    print(dfs(0,-1,k).val());
    
    return 0;
}