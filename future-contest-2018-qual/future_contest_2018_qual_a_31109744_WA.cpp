/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/future-contest-2018-qual/submissions/31109744
 * Submitted at: 2022-04-20 11:38:05
 * Problem URL: https://atcoder.jp/contests/future-contest-2018-qual/tasks/future_contest_2018_qual_a
 * Result: WA
 * Execution Time: 13 ms
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
    //入力受付
    vector<vector<int>> field(100,vector<int>(100,0));
    rep(i,100)rep(j,100)cin >> field[i][j];
    int cnt = 0;

    //出力
    cout << cnt << endl;
    rep(i,100){
        rep(j,100){
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}