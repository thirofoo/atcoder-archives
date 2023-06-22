/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/42827536
 * Submitted at: 2023-06-22 19:42:48
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_m
 * Result: AC
 * Execution Time: 971 ms
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

//セグ木状に乗せる型。
using S = mint;
S op(S a,S b){return a+b;} // operator(作用素)
S e(){return 0;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k; input(n,k);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector<segtree<S,op,e>> dp(n,segtree<S,op,e>(k+1));
    // dp[i][j] : i個目の飴を見て、j人目の飴の個数を決めている時
    rep(i,a[0]+1)dp[0].set(i,1);
    for(ll i=1;i<n;i++){
        rep(j,k+1){
            dp[i].set(j,dp[i-1].prod(max(0LL,j-a[i]),j+1) );
        }
    }
    print( dp[n-1].get(k).val() );
    
    return 0;
}