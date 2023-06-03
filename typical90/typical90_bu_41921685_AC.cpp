/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41921685
 * Submitted at: 2023-06-03 12:10:22
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bu
 * Result: AC
 * Execution Time: 65 ms
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

vector<char> c;
vector<vector<mint>> dp;
vector<vector<ll>> Graph;

void dfs(ll now, ll pre){
    if(Graph[now].size() == 1){
        if(c[now] == 'a')dp[now][0] = 1;
        else dp[now][1] = 1;
    }

    mint t1 = 1, t2 = 1;
    for(auto ele:Graph[now]){
        if(ele == pre)continue;
        dfs(ele,now);
        t1 *= ((c[now] == 'a' ? dp[ele][0] : dp[ele][1])+dp[ele][2]);

        // ここが一番難しいpoint
        // dp[now][2] に含まれるのは、
        // 1. 辺削除する時 → dp[ele][2]のみ。
        // 2. 削除しない時 → dp[]
        // 解説は「条件を満たす全通り - dp[now][('a' or 'b'の状態)]」としている。
        // ※ 仮に c[now] = 'a' とすると、dp[now][1]はありえない為、↑の式で場合の数を表現出来る。
        t2 *= (dp[ele][0]+dp[ele][1]+dp[ele][2] + dp[ele][2]);
    }
    if(c[now] == 'a')dp[now][0] = t1;
    else dp[now][1] = t1;
    dp[now][2] = t2 - t1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    // 部分木が、1.aのみ,2.bのみ,3.両方 でやれば状態列挙可能。
    // 自分は題意を満たすか否かで木dpしようとしたのが敗因。
    ll n; input(n);
    c.assign(n,' ');
    rep(i,n)input(c[i]);
    Graph.assign(n,{});
    rep(i,n-1){
        ll a,b; input(a,b);
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    // dp[i][j] : 要素iを見た時のjを要素と見た時
    dp.assign(n,vector<mint>(3,0));
    dfs(0,-1);
    print( dp[0][2].val() );
    
    
    
    return 0;
}