/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc275/submissions/36068943
 * Submitted at: 2022-10-29 22:28:03
 * Problem URL: https://atcoder.jp/contests/abc275/tasks/abc275_e
 * Result: AC
 * Execution Time: 1026 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m,k; input(n,m,k);
    vector<vector<mint>> dp(k+1,vector<mint>(n+1,0));
    dp[0][0] = 1;
    rep(i,k){
        rep(j,n){
            for(int l=1;l<=m;l++){
                if(j+l <= n){
                    dp[i+1][j+l] += dp[i][j]/m;
                }
                else{
                    ll next = n - (j+l-n);
                    dp[i+1][next] += dp[i][j]/m;
                }
            }
        }
    }

    mint ans = 0;
    for(int i=1;i<=k;i++)ans += dp[i][n];
    print(ans.val());
    
    return 0;
}