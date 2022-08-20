/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc197/submissions/34152822
 * Submitted at: 2022-08-20 11:29:54
 * Problem URL: https://atcoder.jp/contests/abc197/tasks/abc197_e
 * Result: WA
 * Execution Time: 87 ms
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    //自身より右or左を総舐めするのが最善手(?)
    // => 各色において全て回収した先の座標は最小座標か最大座標の2通り?

    //dp[i][j] : j方向から出発し(j=0,1で左右)i色目を回収し終えた時のP(最短距離、現在の座標)
    vector<vector<P>> dp(n+1,vector<P>(2,P(LLONG_MAX,LLONG_MAX)));
    vector<vector<ll>> ball(n);
    rep(i,n){
        ll x,c; cin >> x >> c; c--;
        ball[c].push_back(x);
    }
    rep(i,n)sort(ball[i].begin(),ball[i].end());

    dp[0][0] = P(0LL,0LL),dp[0][1] = P(0LL,0LL);

    rep(i,n){
        rep(j,2){
            auto [c,now] = dp[i][j];
            if(!ball[i].empty()){
                dp[i+1][0] = min(dp[i+1][0], P( (ll)c + abs(ball[i][0]-now)+abs(ball[i][0]-ball[i].back()), ball[i].back() ) );
                dp[i+1][1] = min(dp[i+1][1], P( (ll)c + abs(ball[i].back()-now)+abs(ball[i].back()-ball[i][0]), ball[i][0] ) );
            }
            else{
                dp[i+1][0] = min(P((ll)c,now),dp[i+1][0]);
                dp[i+1][1] = min(P((ll)c,now),dp[i+1][1]);
            }
        }
    }
    cout << min((ll)dp[n][0].first+abs(dp[n][0].second),(ll)dp[n][1].first+abs(dp[n][1].second)) << endl;
    
    return 0;
}