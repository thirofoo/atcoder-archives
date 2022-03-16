/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc029/submissions/30159487
 * Submitted at: 2022-03-16 11:23:42
 * Problem URL: https://atcoder.jp/contests/abc029/tasks/abc029_d
 * Result: AC
 * Execution Time: 8 ms
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

int mod = 1e9 + 7;

int main() {
    string n; cin >> n;
    vector<int> s;
    int size = n.size();
    rep(i,size){
        s.push_back(n[i]-'0');
    }
    vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(2,vector<int>(size+1,0)));
    dp[0][0][0] = 1;
    
    //何桁目か
    rep(i,size){
        //今いる桁として取りうる数字の最大値かそれ未満か
        rep(j,2){
            //今までに1が難解でている数字か
            rep(k,size+1){
                //各桁の数字としてありうるもの(0~9)
                for(int l=0;l<(j ? 10 : s[i]+1);l++){
                    dp[i+1][j || l < s[i]][k + (l == 1 ? 1 : 0)] += dp[i][j][k]; 
                    dp[i+1][j || l < s[i]][k + (l == 1 ? 1 : 0)] %= mod;
                }
            }
        }
    }

    // rep(i,size+1){
    //     rep(k,size+1){
    //         cout << dp[i][0][k] << " ";
    //     }
    //     cout << "  ";
    //     rep(k,size+1){
    //         cout << dp[i][1][k] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    rep(i,size+1)ans += (dp[size][0][i] + dp[size][1][i]) * i;
    cout << ans << endl;
    return 0;
}