/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc241/submissions/29790259
 * Submitted at: 2022-03-01 19:44:28
 * Problem URL: https://atcoder.jp/contests/abc241/tasks/abc241_e
 * Result: AC
 * Execution Time: 292 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

//周期でなくダブリングでの解法
int main() {
    ll n,k; cin >> n >> k;
    vector<int> a(n);
    vector<vector<ll>> doubling(64,vector<ll>(n,0));
    rep(i,n){
        cin >> a[i];
        doubling[0][i] = a[i];
    }
    for(int i=1;i<64;i++){
        rep(j,n){
            //操作2^i回後までに増える飴の数は、2^(i-1)回操作を2回した分に匹敵。
            //右辺の1項目はjから2^(i-1)回操作後の飴の増加個数、
            //2項目は2^(i-1)回操作後から2^i回操作後までの飴の増加個数。
            doubling[i][j] = doubling[i-1][j] + doubling[i-1][(j+doubling[i-1][j])%n];
        }
    }
    ll ans = 0;
    for(int i=0;i<64;i++){
        if(k & (1LL << i))ans += doubling[i][ans%n];
    }
    cout << ans << endl;

    return 0;
}