/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/32669799
 * Submitted at: 2022-06-23 15:09:56
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ak
 * Result: AC
 * Execution Time: 662 ms
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

ll op(ll a,ll b){
    return max(a,b);
}
 
ll e(){
    return -LLONG_MAX;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int w,n; cin >> w >> n;
    vector<segtree<ll,op,e>> dp(n+1,segtree<ll,op,e>(w+1));
    rep(i,n+1)rep(j,w+1)dp[i].set(j,-LLONG_MAX);
    dp[0].set(0,0);

    for(int i=1;i<n+1;i++){
        int l,r,v; cin >> l >> r >> v;
        rep(j,w+1){
            dp[i].set(j,max(dp[i].get(j),dp[i-1].get(j)));
            ll tmp = dp[i-1].prod(max(j-r,0LL),max(j-l+1,0LL));
            if(tmp != -LLONG_MAX)dp[i].set(j,max(tmp+v,dp[i].get(j)));
        }
    }

    cout << (dp[n].get(w) == -LLONG_MAX ? -1 : dp[n].get(w)) << endl;
    
    return 0;
}