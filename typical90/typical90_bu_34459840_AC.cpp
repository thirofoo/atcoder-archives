/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34459840
 * Submitted at: 2022-08-30 20:28:47
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bu
 * Result: AC
 * Execution Time: 68 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<char> ch;
vector<vector<mint>> dp;
vector<vector<ll>> Graph;
vector<bool> visited;

void dfs(int now,int p){

    // 既に探索済みならreturn。
    // if(visited[now])return;

    // 自身の色のみになる遷移と両方の色を持つ遷移を書く。
    // (以下は初期条件を満たす為、別途初期条件を書かなくてよい)

    //1.自身の色のみになる遷移
    bool f = (ch[now] != 'a');
    mint tmp1 = 1,tmp2 = 1;
    for(auto to:Graph[now]){
        if(to == p)continue;
        dfs(to,now);
        // a or bのみの構成になるのは、
        // 1.部分木がa or bのみで構成されてて辺を接続する場合　2.部分木が両方で構成されてて辺を接続しない場合
        tmp1 *= (dp[to][f] + dp[to][2]);
        // a or b の時は接続するかしないかの1択だが、(自身がaで部分木がbのみなら接続するしかない、みたいな)
        // 部分木の時点でab両方あるなら接続してもしなくてもどっちでもいい為、*2してある。
        tmp2 *= (dp[to][0] + dp[to][1] + 2*dp[to][2]);
    }
    dp[now][f] = tmp1;

    // 2.両方の色を持つ遷移
    // 両方の色を持つのは、全体の場合の数-自身の色のみを持つ場合の数 より、
    dp[now][2] = tmp2-tmp1;

    visited[now] = true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC。初の本格的木dp。(今までは深さを求める木dpしかやったことない。)
    ll n; cin >> n;
    ch.assign(n,' ');
    rep(i,n)cin >> ch[i];
    Graph.assign(n,{});
    rep(i,n-1){
        ll a,b; cin >> a >> b; a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    // dp[i][j] : 頂点iを親とした木がjの状態の時の場合の数。(j=0 : aのみで構成、j=1 : bのみで構成、j=2 : 両方で構成)
    dp.assign(n,vector<mint>(3,0));
    visited.assign(n,false);
    dfs(0,-1);
    cout << dp[0][2].val() << endl;
    
    return 0;
}