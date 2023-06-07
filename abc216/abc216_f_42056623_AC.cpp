/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc216/submissions/42056623
 * Submitted at: 2023-06-07 17:50:14
 * Problem URL: https://atcoder.jp/contests/abc216/tasks/abc216_f
 * Result: AC
 * Execution Time: 153 ms
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
    vector<ll> a(n),b(n);
    vector<P> p;
    rep(i,n)input(a[i]);
    rep(i,n)input(b[i]);
    rep(i,n)p.push_back(P(a[i],b[i]));
    sort(p.begin(),p.end());

    vector<vector<mint>> dp(n+1,vector<mint>(5002,0));
    dp[0][0] = 1;
    rep(i,n){
        auto [x,y] = p[i];
        rep(j,5001){
            dp[i+1][j] += dp[i][j];
            dp[i+1][min(5001LL,j+y)] += dp[i][j];
        }
    }

    mint ans = 0;
    rep(i,n){
        auto [x,y] = p[i];
        // max(A) = x となるように探索
        // y は絶対利用しなくちゃいけないことを考慮
        for(ll j=0;j<=x-y;j++){
            ans += dp[i][j];
        }
    }
    print(ans.val());

    return 0;
}