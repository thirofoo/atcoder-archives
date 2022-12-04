/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc201/submissions/37016738
 * Submitted at: 2022-12-04 18:32:46
 * Problem URL: https://atcoder.jp/contests/abc201/tasks/abc201_d
 * Result: WA
 * Execution Time: 52 ms
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
    // dp[i][j] : ijマスでの高橋と青木君の得点差
    vector<vector<ll>> dp(h,vector<ll>(w,-1e15));
    dp[h-1][w-1] = 0;
    for(int i=h-1;i>=0;i--){
        for(int j=w-1;j>=0;j--){
            if(i == h-1 && j == w-1)continue;
            if(i != h-1)dp[i][j] = max(dp[i][j],-dp[i+1][j]+(field[i+1][j] == '+' ? 1 : -1));
            if(j != w-1)dp[i][j] = max(dp[i][j],-dp[i][j+1]+(field[i][j+1] == '+' ? 1 : -1));
        }
    }
    if((h+w)%2 == 1){
        if(dp[0][0] == 0)print("Draw");
        else if(dp[0][0] > 0)print("Aoki");
        else print("Takahashi");
    }
    else{
        if(dp[0][0] == 0)print("Draw");
        else if(dp[0][0] > 0)print("Takahashi");
        else print("Aoki");
    }
    
    return 0;
}