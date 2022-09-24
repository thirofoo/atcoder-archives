/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc270/submissions/35145104
 * Submitted at: 2022-09-25 01:18:39
 * Problem URL: https://atcoder.jp/contests/abc270/tasks/abc270_d
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll n,k; input(n,k);
    vector<ll> a(k);
    rep(i,k)input(a[i]);
    vector<ll> dp(n+1,-LLONG_MAX);
    dp[0] = 0;
    rep(i,n+1){
        rep(j,k){
            if(i-a[j] < 0)continue;
            dp[i] = max(dp[i],a[j] + i-a[j]-dp[i-a[j]]);
        }
    }
    print(dp[n]);
    
    return 0;
}