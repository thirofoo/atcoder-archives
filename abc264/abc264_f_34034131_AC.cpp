/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc264/submissions/34034131
 * Submitted at: 2022-08-14 12:41:32
 * Problem URL: https://atcoder.jp/contests/abc264/tasks/abc264_f
 * Result: AC
 * Execution Time: 1178 ms
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
    
    ll h,w; cin >> h >> w;
    vector<ll> r(h),c(w);
    vector<string> field(h);
    rep(i,h)cin >> r[i];
    rep(i,w)cin >> c[i];
    rep(i,h)cin >> field[i];

    //dp。反転回数は0or1でokなのが肝。
    //dp[i][j][k][l] : i*j平面でkl状態(行反転されているか、列反転されてるか)されてる時の最小コスト。
    //※3,4次元目は縦横の反転数を別々で管理するために必要。
    vector dp(h,vector<vector<vector<ll>>>(w,vector<vector<ll>>(2,vector<ll>(2,LLONG_MAX))));
    vector<int> dx = {0,1};
    vector<int> dy = {1,0};
    dp[0][0][0][0] = 0; dp[0][0][1][0] = r[0]; dp[0][0][0][1] = c[0]; dp[0][0][1][1] = r[0]+c[0];
    rep(i,h){
        rep(j,w){
            rep(k,2){
                rep(l,2){
                    if(dp[i][j][k][l] == LLONG_MAX)continue;
                    //now : 今の反転状態
                    int now = (field[i][j]-'0')^k^l;

                    //dp[i][j][k][l]から→or↑に行くfor文
                    rep(m,2){
                        int nx = i+dx[m],ny = j+dy[m];
                        if(nx >= h || ny >= w)continue;

                        bool f;
                        if(m == 0){
                            f = ( now == (field[nx][ny]-'0')^k );
                            dp[nx][ny][k][!f] = min(dp[nx][ny][k][!f],dp[i][j][k][l]+(f ? 0 : c[ny]));
                        }
                        else{
                            f = ( now == (field[nx][ny]-'0')^l );
                            dp[nx][ny][!f][l] = min(dp[nx][ny][!f][l],dp[i][j][k][l]+(f ? 0 : r[nx]));
                        }
                    }
                }
            }
        }
    }

    //この解放はx。あるマスにおいて行も列も反転されたケースを考慮出来ていない。

    ll ans = LLONG_MAX;
    rep(k,2)rep(l,2)ans = min(ans,dp[h-1][w-1][k][l]);
    cout << ans << endl;
    
    return 0;
}