/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc054/submissions/29045180
 * Submitted at: 2022-02-04 23:31:35
 * Problem URL: https://atcoder.jp/contests/abc054/tasks/abc054_d
 * Result: WA
 * Execution Time: 34 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

const int nmax=40,abmax=10,inf = 1000000;
int a[nmax],b[nmax],c[nmax];
int dp[nmax+1][nmax*abmax+1][nmax*abmax+1];

int main(void){
    //解説AC
    int n,ma,mb;
    cin >> n >> ma >> mb;
    for(int i=0;i<n;++i){
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 0; i <= n; ++i){
        for(int ca = 0; ca <= nmax*abmax; ++ca){
            for(int cb = 0; cb <= nmax*abmax; ++cb){
                dp[i][ca][cb]=inf;
            }
        }
    }

    dp[0][0][0]=0;

    for(int i = 0; i < n; ++i){
        for(int ca = 0; ca <= nmax*abmax; ++ca){
            for(int cb = 0; cb <= nmax*abmax; ++cb){
                if(dp[i][ca][cb]==inf) continue;
                dp[i+1][ca][cb]=min(dp[i+1][ca][cb],dp[i][ca][cb]);
                dp[i+1][ca+a[i]][cb+b[i]]=min(dp[i+1][ca+a[i]][cb+b[i]],dp[i][ca][cb]+c[i]);
            }
        }
    }

    int ans=inf;
    for(int ca = 1; ca <= nmax*abmax; ++ca){
        for(int cb = 1; cb <= nmax*abmax; ++cb){
            if(ca*mb==cb*ma) ans=min(ans,dp[n][ca][cb]);
        }
    }

    rep(i,11){
        rep(j,11){
            cout << dp[n-1][i][j] << " ";
        }
        cout << endl;
    }

    rep(i,11){
        rep(j,11){
            cout << dp[n][i][j] << " ";
        }
        cout << endl;
    }

    if(ans==inf) ans=-1;
    cout << ans << endl;

    return 0;
}