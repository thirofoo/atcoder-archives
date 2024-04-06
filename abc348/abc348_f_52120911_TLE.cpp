/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc348/submissions/52120911
 * Submitted at: 2024-04-07 00:07:09
 * Problem URL: https://atcoder.jp/contests/abc348/tasks/abc348_f
 * Result: TLE
 * Execution Time: 2211 ms
 */

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    short A[M][N];
    rep(i,N) rep(j,M) cin >> A[j][i];
    bool cnt[N][N];
    rep(i,N) rep(j,N) cnt[i][j]=false;
    rep(i,M){
        rep(j,N) for(int k=j+1;k<N;k++) cnt[j][k]^=(A[i][j]==A[i][k]);
    }
    int ans=0;
    rep(i,N) for(int j=i+1;j<N;j++) ans+=cnt[i][j];
    cout << ans << endl;
}