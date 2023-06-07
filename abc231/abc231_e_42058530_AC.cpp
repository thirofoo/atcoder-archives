/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/42058530
 * Submitted at: 2023-06-07 19:45:25
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_e
 * Result: AC
 * Execution Time: 9 ms
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

ll n,x;
vector<ll> a;
map<ll,ll> dp;

ll dfs(ll x, ll i){
    if(i == n-1)dp[x] = x/a[i];
    if(dp.count(x) && dp[x] != LLONG_MAX)return dp[x];
    
    // 硬貨iの用い方
    // 1. 硬貨iでi+1以降で払えない端数分を払う
    // 2. 硬貨i+1を用いて、お釣りを硬貨iで貰う
    // point : A_i+1 以降は A_i の倍数 → x%A_{i+1} が端数分
    dp[x] = LLONG_MAX;
    // r1 : 1の端数分, r2 : 2の過剰払い分
    ll r1 = x%a[i+1], r2 = (a[i+1]-x%a[i+1]) % a[i+1];
    dp[x] = min( dp[x],dfs( x - r1, i+1 ) + r1/a[i] ); // 1
    dp[x] = min( dp[x],dfs( x + r2, i+1 ) + r2/a[i] ); // 2
    return dp[x];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n,x);
    a.assign(n,0);
    rep(i,n)input(a[i]);
    print(dfs(x,0));
    
    return 0;
}