/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc179/submissions/34506279
 * Submitted at: 2022-09-02 15:26:47
 * Problem URL: https://atcoder.jp/contests/abc179/tasks/abc179_d
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k; input(n,k);
    vector<P> range;
    rep(i,k){
        ll l,r; input(l,r);
        range.push_back(P(l,r+1));
    }
    vector<mint> dp(n+1,0);
    dp[1] = 1;
    for(ll i=2;i<=n;i++){
        for(auto [l,r]:range){
            dp[i] += dp[max(i-l,0LL)]-dp[max(i-r,0LL)];
        }
        dp[i] += dp[i-1];
    }

    print((dp[n]-dp[n-1]).val());
    
    return 0;
}