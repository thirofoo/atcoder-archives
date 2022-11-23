/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/36744075
 * Submitted at: 2022-11-24 00:31:45
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_e
 * Result: AC
 * Execution Time: 7 ms
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
    cout << setprecision(6) << fixed;
    
    ll n; input(n);
    vector<ld> dp(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(j >= dp[i-1])dp[i] += j;
            else dp[i] += dp[i-1];
        }
        dp[i] /= 6;
    }
    print(dp[n]);
    
    return 0;
}