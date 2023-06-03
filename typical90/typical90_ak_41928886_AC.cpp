/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41928886
 * Submitted at: 2023-06-03 17:27:55
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ak
 * Result: AC
 * Execution Time: 582 ms
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
S e(){return -1;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // セグ木をのせたdp
    ll w,n; input(w,n);
    vector<T> cook;
    rep(i,n){
        ll l,r,v; input(l,r,v);
        cook.push_back(T(l,r,v));
    }
    vector<segtree<S,op,e>> dp(n+1,segtree<S,op,e>(w+1));
    dp[0].set(0,0);
    for(ll i=1;i<=w;i++)dp[0].set(i,-1);
    for(ll i=1;i<=n;i++){
        auto &&[l,r,v] = cook[i-1];
        rep(j,w+1){
            dp[i].set(j, max(dp[i].get(j), dp[i-1].get(j)));
            ll cand = dp[i-1].prod(max(j-r,0LL) , max(j-l+1,0LL));
            if(cand == -1)continue;
            dp[i].set(j, max(dp[i].get(j), cand+v));
        }
    }
    print( dp[n].get(w) );
    
    return 0;
}