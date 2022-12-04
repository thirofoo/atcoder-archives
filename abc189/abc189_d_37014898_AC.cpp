/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc189/submissions/37014898
 * Submitted at: 2022-12-04 17:12:42
 * Problem URL: https://atcoder.jp/contests/abc189/tasks/abc189_d
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
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<string> s(n);
    rep(i,n)input(s[i]);
    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    dp[0][0] = 1; dp[0][1] = 1;
    rep(i,n){
        if(s[i] == "AND"){
            dp[i+1][0] += dp[i][0];
            dp[i+1][0] += dp[i][0];
            dp[i+1][0] += dp[i][1];
            dp[i+1][1] += dp[i][1];
        }
        else{
            dp[i+1][0] += dp[i][0];
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] += dp[i][1];
            dp[i+1][1] += dp[i][1];
        }
    }
    print(dp[n][1]);
    
    return 0;
}