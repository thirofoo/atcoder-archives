/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc046/submissions/38943520
 * Submitted at: 2023-02-17 19:50:06
 * Problem URL: https://atcoder.jp/contests/agc046/tasks/agc046_b
 * Result: AC
 * Execution Time: 102 ms
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
    
    ll a,b,c,d; input(a,b,c,d);
    vector<vector<mint>> dp(c,vector<mint>(d,0));
    dp[a-1][b-1] = 1;
    for(int i=a-1;i<c;i++){
        for(int j=b-1;j<d;j++){
            if(i == a-1 && j == b-1)continue;
            else if(i == a-1)dp[i][j] = dp[i][j-1]*(i+1);
            else if(j == b-1)dp[i][j] = dp[i-1][j]*(j+1);
            else dp[i][j] = dp[i][j-1]*(i+1) + dp[i-1][j]*(j+1) - dp[i-1][j-1]*i*j;
        }
    }

    print(dp[c-1][d-1].val());
    
    return 0;
}