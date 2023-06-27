/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/43007954
 * Submitted at: 2023-06-28 00:12:16
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_q
 * Result: AC
 * Execution Time: 72 ms
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

//セグ木状に乗せる型。
using S = ll;

S op(S a,S b){return max(a,b);} // operator(作用素)
S e(){return 0;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> h(n),a(n);
    rep(i,n)input(h[i]);
    rep(i,n)input(a[i]);
    segtree<S,op,e> dp(n+1);
    S ans = 0;
    rep(i,n){
        dp.set(h[i],a[i]+dp.prod(0,h[i]));
        ans = max(ans,dp.prod(h[i],h[i]+1));
    }
    print(ans);
    
    return 0;
}