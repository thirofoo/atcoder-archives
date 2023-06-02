/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc243/submissions/41904383
 * Submitted at: 2023-06-02 15:12:54
 * Problem URL: https://atcoder.jp/contests/abc243/tasks/abc243_e
 * Result: AC
 * Execution Time: 51 ms
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
    // 1. 全頂点対最短経路を求める
    // 2. 最短経路が辺の重みより軽い時 → 不要
    //    　　　　〃　　　　と同じ時 　→ その辺以外で最短経路を満たすものがあれば不要
    vector<vector<ll>> dp(n,vector<ll>(n,1e16)),multi(n,vector<ll>(n,0));
    vector<T> edge;
    rep(i,m){
        ll a,b,c; input(a,b,c);
        a--; b--;
        edge.push_back(T(a,b,c));
        dp[a][b] = c;
        dp[b][a] = c;
    }
    rep(i,n)dp[i][i] = 0;

    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(dp[i][k]+dp[k][j] == dp[i][j] && (i != j && j != k && i != k)){
                    multi[i][j]++;
                }
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    
    ll ans = 0;
    rep(i,m){
        auto [a,b,c] = edge[i];
        if(dp[a][b] == c && !multi[a][b])continue;
        ans++;
    }
    print(ans);
    
    return 0;
}   