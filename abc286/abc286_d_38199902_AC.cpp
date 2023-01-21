/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc286/submissions/38199902
 * Submitted at: 2023-01-21 21:13:07
 * Problem URL: https://atcoder.jp/contests/abc286/tasks/abc286_d
 * Result: AC
 * Execution Time: 35 ms
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
    
    ll n,x; input(n,x);
    vector<P> c;
    rep(i,n){
        ll a,b; input(a,b);
        c.push_back(P(a,b));
    }
    vector dp(n+1,vector<bool>(x+1,false));
    dp[0][0] = true;
    rep(i,n){
        auto [a,b] = c[i];
        rep(j,x+1){
            if(!dp[i][j])continue;
            rep(k,b+1){
                if(j+a*k > x)break;
                dp[i+1][j+a*k] = true;
            }
        }
    }
    print(dp[n][x] ? "Yes" : "No");
    
    return 0;
}