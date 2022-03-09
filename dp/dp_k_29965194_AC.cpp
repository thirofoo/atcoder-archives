/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29965194
 * Submitted at: 2022-03-09 11:43:18
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_k
 * Result: AC
 * Execution Time: 34 ms
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
typedef modint1000000007 mint1;
typedef modint998244353 mint2;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    //dp[i]:i個までの石を使ったときの先手の勝敗。
    vector<bool> dp(k+1,false);
    //勝敗がつく一手前の手を考える。
    //先手必勝の石 => 後手がいかなる手を出しても先手がその石を取ることが可能。
    //後手必勝の石 => 先手がいかなる手を出しても後手がその石を取ることが可能。
    // => 最後の石の1手前の状況を相手に押し付けることが出来る。(1手前の状況が自分と相手で変わる)
    // => 最後の石の1手前が1つでも後手必勝ならその状況をひっくりかえせる。
    rep(i,k+1){
        rep(j,n){
            if(i-a[j] >= 0 && dp[i-a[j]] == 0)dp[i] = 1;
        }
    }
    cout << (dp[k] ? "First" : "Second") << endl;
    return 0;
}