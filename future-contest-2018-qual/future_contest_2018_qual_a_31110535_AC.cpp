/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/future-contest-2018-qual/submissions/31110535
 * Submitted at: 2022-04-20 12:43:42
 * Problem URL: https://atcoder.jp/contests/future-contest-2018-qual/tasks/future_contest_2018_qual_a
 * Result: AC
 * Execution Time: 12 ms
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
    vector<T> query;
    rep(i,100)rep(j,100)cin >> field[i][j];
    int cnt = 0;

    //出力
    cout << cnt << endl;
    rep(i,cnt){
        auto [x,y,h] = query[i];
        cout << x << " " << y << " " << h << endl;
    }

    return 0;
}