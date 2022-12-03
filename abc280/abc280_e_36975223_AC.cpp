/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc280/submissions/36975223
 * Submitted at: 2022-12-03 21:31:13
 * Problem URL: https://atcoder.jp/contests/abc280/tasks/abc280_e
 * Result: AC
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,p; input(n,p);
    vector<mint> dp(n+1);
    dp[0] = 0; dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = (dp[i-2]+1)*p/100 + (dp[i-1]+1)*(100-p)/100;
    }
    print(dp[n].val());
    
    return 0;
}