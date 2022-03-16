/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/30159946
 * Submitted at: 2022-03-16 12:04:23
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_s
 * Result: WA
 * Execution Time: 209 ms
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

int mod = 1e9 + 7;

int main() {
    string s; int d; cin >> s >> d;
    int size = s.size();
    vector<vector<vector<mint>>> dp(size+1,vector<vector<mint>>(2,vector<mint>(d,0)));
    dp[0][0][0] = 1;
    rep(i,size){
        rep(j,2){
            rep(k,d){
                for(int l=0;l<=(j ? 9 : s[i]-'0');l++){
                    dp[i+1][j || l < s[i]-'0'][(k+l)%d] += dp[i][j][k];
                }
            }
        }
    }

    //0が含まれている為その分を引く。
    cout << (dp[size][0][0].val() + dp[size][1][0].val() - 1)%mod << endl;
    return 0;
}