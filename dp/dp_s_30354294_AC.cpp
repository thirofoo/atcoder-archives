/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/30354294
 * Submitted at: 2022-03-23 00:13:19
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_s
 * Result: AC
 * Execution Time: 197 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int mod = 1e9+7;

int main() {
    string k; int d; cin >> k >> d;
    int size = k.size();
    vector<vector<vector<mint>>> dp(size+1,vector<vector<mint>>(2,vector<mint>(d,0)));
    dp[0][0][0] = 1;

    rep(i,size){
        rep(j,2){
            rep(l,d){
                for(int m=0;m<=(j ? 9 : k[i]-'0');m++){
                    dp[i+1][j || m != k[i]-'0'][(l+m)%d] += dp[i][j][l];
                }
            }
        }
    }
    cout << (dp[size][0][0].val() + dp[size][1][0].val() -1 + mod)%mod << endl;

    return 0;
}