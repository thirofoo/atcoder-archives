/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc265/submissions/34244117
 * Submitted at: 2022-08-21 22:34:50
 * Problem URL: https://atcoder.jp/contests/abc265/tasks/abc265_e
 * Result: WA
 * Execution Time: 3319 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m,a,b,c,d,e,f; cin >> n >> m >> a >> b >> c >> d >> e >> f;
    map<P,bool> ng,cnt;
    rep(i,m){
        ll x,y; cin >> x >> y;
        ng[P(x,y)] = true;
    }
    //dp[i][j][k] : 1,2,3の操作をそれぞれ何回やったか
    ll x1,x2,x3,y1,y2,y3;
    vector dp(n+1,vector<vector<mint>>(n+1,vector<mint>(n+1,0)));
    dp[0][0][0] = 1;
    rep(i,n){
        for(int j=0;j<=n;j++){
            if(i-j < 0)break;
            for(int k=0;k<=n;k++){
                int l = i-j-k;
                if(l < 0)break;
                // cout << j << " " << k << " " << l << endl;
                x1 = (j+1)*a+k*c+l*e,y1 = (j+1)*b+k*d+l*f;
                x2 = j*a+(k+1)*c+l*e,y2 = j*b+(k+1)*d+l*f;
                x3 = j*a+k*c+(l+1)*e,y3 = j*b+k*d+(l+1)*f;
                if(x1 >= -1000000000 && x1 <= 1000000000 && y1 >= -1000000000 && y1 <= 1000000000){
                    if(!ng[P(x1,y1)])dp[j+1][k][l] += dp[j][k][l];
                    else ng.erase(P(x1,y1));
                    // cout << x1 << " " << y1 << " : " << dp[j+1][k][l].val() << endl;
                }
                if(x2 >= -1000000000 && x2 <= 1000000000 && y2 >= -1000000000 && y2 <= 1000000000){
                    if(!ng[P(x2,y2)])dp[j][k+1][l] += dp[j][k][l];
                    else ng.erase(P(x2,y2));
                    // cout << x2 << " " << y2 << " : " << dp[j][k+1][l].val() << endl;
                }
                if(x3 >= -1000000000 && x3 <= 1000000000 && y3 >= -1000000000 && y3 <= 1000000000){
                    if(!ng[P(x3,y3)])dp[j][k][l+1] += dp[j][k][l];
                    else ng.erase(P(x3,y3));
                    // cout << x3 << " " << y3 << " : " << dp[j][k][l+1].val() << endl;
                }
                // cout << endl;
            }
        }
    }

    mint ans = 0;
    for(ll j=0;j<=n;j++){
        if(n-j < 0)break;
        for(ll k=0;k<=n;k++){
            ll l = n-j-k;
            if(l < 0)break;
            //同じ座標or行けない座標の時以外加える。
            ll x = j*a+k*c+l*e,y = j*b+k*d+l*f;
            if(!cnt[P(x,y)] && x >= -1000000000 && x <= 1000000000 && y >= -1000000000 && y <= 1000000000){
                // cout << x << " " << y << endl;
                ans += dp[j][k][l];
                cnt[P(x,y)] = true;
            }
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}