/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc201/submissions/37016109
 * Submitted at: 2022-12-04 18:05:21
 * Problem URL: https://atcoder.jp/contests/abc201/tasks/abc201_d
 * Result: WA
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
    
    ll h,w; input(h,w);
    vector<string> field(h);
    rep(i,h)input(field[i]);
    // dp[i][j] : ijマスでの高橋or青木君の得点
    vector<vector<ll>> dp(h,vector<ll>(w,1e15));
    dp[0][0] = 0;
    rep(i,h){
        rep(j,w){
            if(i == 0 && j == 0)continue;
            if(i != 0)dp[i][j] = min(dp[i][j],-dp[i-1][j]+(field[i][j] == '+' ? 1 : -1));
            if(j != 0)dp[i][j] = min(dp[i][j],-dp[i][j-1]+(field[i][j] == '+' ? 1 : -1));
            // cout << dp[i][j] << " ";
        }
        // print();
    }
    if((h+w)%2 == 0){
        if(dp[h-1][w-1] == 0)print("Draw");
        else if(dp[h-1][w-1] > 0)print("Aoki");
        else print("Takahashi");
    }
    else{
        if(dp[h-1][w-1] == 0)print("Draw");
        else if(dp[h-1][w-1] > 0)print("Takahashi");
        else print("Aoki");
    }
    
    return 0;
}