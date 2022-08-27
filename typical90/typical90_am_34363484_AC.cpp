/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34363484
 * Submitted at: 2022-08-27 18:24:51
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_am
 * Result: AC
 * Execution Time: 48 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

//メモ化再起(木dp)
vector<vector<ll>> Graph;
vector<ll> junior;
void dfs(int now,int pre){
    junior[now] = 1;
    for(int next:Graph[now]){
        if(next != pre){
            dfs(next,now);
            junior[now] += junior[next];
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    //解説AC。頭良すぎ。
    ll n; cin >> n;
    rep(i,n)Graph.push_back({});
    rep(i,n-1){
        int a,b; cin >> a >> b; a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    //頂点1を根とした時の自身を含めた子ノードのサイズを求める再起。
    junior.assign(n,0);
    dfs(0,-1);

    //各辺の貢献度の総和を求める。
    ll ans = 0;
    rep(i,n){
        for(auto s:Graph[i]){
            if(junior[i] < junior[s])continue;
            ans += junior[s]*(n-junior[s]);
        }
    }
    cout << ans << endl;
    
    return 0;
}