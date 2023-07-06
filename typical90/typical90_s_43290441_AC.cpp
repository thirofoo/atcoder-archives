/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/43290441
 * Submitted at: 2023-07-06 17:24:56
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_s
 * Result: AC
 * Execution Time: 54 ms
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
    vector<ll> a(2*n);
    rep(i,2*n) input(a[i]);
    vector<vector<ll>> dp(2*n,vector<ll>(2*n,1e16));

    auto f = [&](auto self, ll left, ll right){
        if( (right-left)%2 == 0 ) return (ll)1e16;
        if( dp[left][right] != 1e16 ) return dp[left][right];
        if( left+1 == right ) return (dp[left][right] = abs(a[right]-a[left]));

        dp[left][right] = min(dp[left][right], self(self, left+1,right-1) + abs(a[right]-a[left]));

        for(ll i=left+1;i<right-1;i++){
            dp[left][right] = min(dp[left][right], self(self, left,i) + self(self, i+1,right));
        }
        return dp[left][right];
    };

    print( f(f, 0,2*n-1) );
    
    return 0;
}