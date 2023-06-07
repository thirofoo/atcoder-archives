/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/42060871
 * Submitted at: 2023-06-07 21:49:49
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_k
 * Result: AC
 * Execution Time: 166 ms
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
    
    // 解説AC
    // 今回の問題は締め切りがあることがネック
    // → 『締め切りが速いものほど先にすべき』は常に言える
    // → 締め切り順にdpすることが最善の手
    // ( 入力のままdpすると、前半に入れれば行けたけど締め切りのせいでx というケースが存在 )
    ll n; input(n);
    vector<T> info;
    rep(i,n){
        ll d,c,s; input(d,c,s);
        info.push_back(T(d,c,s));
    }
    sort(info.begin(),info.end());
    // dp[i][j] : i番目までのタスクを見て、合計時間jの時の最大スコア
    vector<vector<ll>> dp(n+1,vector<ll>(5002,0));
    rep(i,n){
        auto &&[d,c,s] = info[i];
        rep(j,5001){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if(j+c <= d)dp[i+1][j+c] = max(dp[i+1][j+c],dp[i][j]+s);
        }
    }
    ll ans = 0;
    rep(i,5001)ans = max(ans,dp[n][i]);
    print(ans);
    
    return 0;
}