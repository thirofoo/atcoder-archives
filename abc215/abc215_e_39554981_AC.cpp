/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc215/submissions/39554981
 * Submitted at: 2023-03-09 18:30:52
 * Problem URL: https://atcoder.jp/contests/abc215/tasks/abc215_e
 * Result: AC
 * Execution Time: 105 ms
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
    
    ll n; string s; input(n,s);
    vector dp(n+1,vector<vector<mint>>((1LL << 10),vector<mint>(10,0)));
    dp[0][0][0] = 1;
    rep(i,n){
        rep(j,1LL << 10){
            rep(k,10){
                // 使用しない場合
                dp[i+1][j][k] += dp[i][j][k];
                // 使用する場合
                if( (j & (1LL << (s[i]-'A'))) && k != s[i]-'A' )continue;
                dp[i+1][j | (1LL << (s[i]-'A'))][s[i]-'A'] += dp[i][j][k];
            }
        }
    }
    mint ans = 0;
    rep(i,1LL << 10)rep(j,10)ans += dp[n][i][j];
    print((ans-1).val());

    return 0;
}