/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/43013538
 * Submitted at: 2023-06-28 09:29:49
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_t
 * Result: AC
 * Execution Time: 60 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    // パッと見 bitDP したくなる → O(N^2*2^N) で当たり前のように死亡
    // → 今回は後ろの数字が何か・直前の数字が何か まで状態を持たなくとも、
    //   『自分より大きい数字がj個存在する』 が分かるだけで次が分かる。
    //    ( 自分より大きい要素が多い状態から低い状態に移る感じ )

    ll n; string s; input(n,s);
    vector<vector<mint>> dp(n,vector<mint>(n+1,0));
    // dp[i][j] : i文字目まで見て、現在より大きい数字がj-1個存在する時の場合の数
    rep(i,n)dp[0][i+1] = dp[0][i] + 1;

    for(ll i=1;i<n;i++){
        // i行目は自身より大きい数字の個数は 0 ~ N-i 個の間
        for(ll j=1;j<=n-i;j++){
            // 自身より大きい数字がこれから来る → jは小さくなる遷移
            if(s[i-1] == '<')dp[i][j] += (dp[i-1][n-i+1] - dp[i-1][j]);
            // 自身より小さい数字がこれから来る → jは大きくなる遷移
            else dp[i][j] += (dp[i-1][j] - dp[i-1][0]);
        }
        rep(j,n)dp[i][j+1] += dp[i][j];
    }

    print(dp[n-1][1].val());
    
    return 0;
}