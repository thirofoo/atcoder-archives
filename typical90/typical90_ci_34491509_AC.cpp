/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34491509
 * Submitted at: 2022-09-01 18:03:51
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ci
 * Result: AC
 * Execution Time: 18 ms
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

ll n,p,k;
vector<vector<ll>> cost;

ll minCost(ll b){
    ll left = 0,right = 1e16;
    while(right-left > 1){
        // mid : Aij = -1の時の交通料金
        // => pスヌーク以内でb以上の行き来可能ペアが生じる最大料金を求めている。
        ll mid = (right+left)/2;

        //ワーシャルフロイド
        vector dp(n,vector<ll>(n,0));
        rep(i,n)rep(j,n)dp[i][j] = (cost[i][j] == -1 ? mid : cost[i][j]);
        rep(l,n){
            rep(i,n){
                rep(j,n){
                    dp[i][j] = min(dp[i][j],dp[i][l]+dp[l][j]);
                }
            }
        }
        ll cnt = 0;
        rep(i,n)for(ll j=i+1;j<n;j++){
            if(dp[i][j] <= p)cnt++;
        }
        if(cnt >= b)left = mid;
        else right = mid;
    }
    return left;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input(n,p,k);
    cost.assign(n,vector<ll>(n));
    rep(i,n)rep(j,n)input(cost[i][j]);

    ll k1 = minCost(k),k2 = minCost(k+1);
    // infinityになる条件：いくら値段を上げてもk個より多くのペアが作成できてしまう場合。
    if(k1-k2 > 1e12)print("Infinity");
    else print(k1-k2);
    
    return 0;
}