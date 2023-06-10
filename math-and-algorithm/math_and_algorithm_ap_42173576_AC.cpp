/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/math-and-algorithm/submissions/42173576
 * Submitted at: 2023-06-11 00:40:31
 * Problem URL: https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_ap
 * Result: AC
 * Execution Time: 55 ms
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
    
    ll n; input(n);
    vector<mint> dp(n+1);
    dp[1] = 1; dp[2] = 1;
    for(ll i=3;i<=n;i++)dp[i] = dp[i-1] + dp[i-2];
    print(dp[n].val());
    
    return 0;
}