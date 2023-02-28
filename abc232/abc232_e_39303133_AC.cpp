/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc232/submissions/39303133
 * Submitted at: 2023-02-28 10:20:00
 * Problem URL: https://atcoder.jp/contests/abc232/tasks/abc232_e
 * Result: AC
 * Execution Time: 91 ms
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
    
    ll h,w,k,x1,y1,x2,y2; input(h,w,k,x1,y1,x2,y2);
    vector<vector<mint>> dp(k+1,vector<mint>(4,0));
    if(x1 == x2 && y1 == y2)dp[0][0] = 1;
    else if(x1 == x2)dp[0][1] = 1;
    else if(y1 == y2)dp[0][2] = 1;
    else dp[0][3] = 1;
    rep(i,k){
        dp[i+1][0] += dp[i][1] + dp[i][2];
        dp[i+1][1] += dp[i][0]*(w-1) + dp[i][1]*(w-2) + dp[i][3];
        dp[i+1][2] += dp[i][0]*(h-1) + dp[i][2]*(h-2) + dp[i][3];
        dp[i+1][3] += dp[i][1]*(h-1) + dp[i][2]*(w-1) + dp[i][3]*(h+w-2-2);
    }
    print( dp[k][0].val() );
    
    return 0;
}