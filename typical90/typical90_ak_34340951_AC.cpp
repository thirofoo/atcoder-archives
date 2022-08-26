/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34340951
 * Submitted at: 2022-08-26 14:03:24
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ak
 * Result: AC
 * Execution Time: 548 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

//セグ木状に乗せる型。
using S = ll;

S op(S a,S b){return max(a,b);} // operator(作用素)
S e(){return -1;} // 単位元 (op(e,a) = a)
int V;
bool f(S a){return a < V;} // min_leftを用いる時のbool関数

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll w,n; cin >> w >> n;
    vector dp(n+1,segtree<S,op,e>(w+1));
    dp[0].set(0,0);
    for(int i=1;i<=n;i++){
        ll l,r,v; cin >> l >> r >> v;
        rep(j,w+1){
            dp[i].set(j,max(dp[i].get(j),dp[i-1].get(j)));
            if(j != 0){
                S tmp = dp[i-1].prod( max(0LL,j-r) , max(0LL,j-l+1));
                if(tmp != -1)dp[i].set(j , max(dp[i].get(j) , tmp+v ));
            }
        }
    }
    cout << dp[n].get(w) << endl;
    
    return 0;
}