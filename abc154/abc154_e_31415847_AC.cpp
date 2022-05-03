/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc154/submissions/31415847
 * Submitted at: 2022-05-03 18:19:26
 * Problem URL: https://atcoder.jp/contests/abc154/tasks/abc154_e
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    string n;int k; cin >> n >> k;
    int size = n.size();
    vector<vector<vector<ll>>> dp(size+1,vector<vector<ll>>(2,vector<ll>(k+2,0)));
    dp[0][0][0] = 1;
    rep(i,size){
        rep(j,2){
            rep(l,k+1){
                for(int m=0;m<=(j ? 9 : n[i]-'0');m++){
                    int nj = j || (m < n[i]-'0');
                    int nl = l + (m != 0);
                    dp[i+1][nj][nl] += dp[i][j][l];
                }
            }
        }
    }

    cout << dp[size][0][k]+dp[size][1][k] << endl;
    return 0;
}