/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc291/submissions/39236695
 * Submitted at: 2023-02-26 21:10:31
 * Problem URL: https://atcoder.jp/contests/abc291/tasks/abc291_d
 * Result: AC
 * Execution Time: 61 ms
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
    
    ll n; input(n);
    vector<P> card;
    rep(i,n){
        ll a,b; input(a,b);
        card.emplace_back(P(a,b));
    }
    vector<vector<mint>> dp(n,vector<mint>(2,0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep(i,n-1){
        auto [a1,b1] = card[i];
        auto [a2,b2] = card[i+1];
        if(a1 != a2)dp[i+1][0] += dp[i][0];
        if(a1 != b2)dp[i+1][1] += dp[i][0];
        if(b1 != a2)dp[i+1][0] += dp[i][1];
        if(b1 != b2)dp[i+1][1] += dp[i][1];
    }
    print((dp[n-1][0] + dp[n-1][1]).val());
    
    return 0;
}