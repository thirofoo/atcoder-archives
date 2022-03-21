/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30319246
 * Submitted at: 2022-03-21 12:53:59
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_d
 * Result: AC
 * Execution Time: 760 ms
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
    int h,w; cin >> h >> w;
    vector<vector<int>> field(h,vector<int>(w));
    rep(i,h)rep(j,w)cin >> field[i][j];

    vector<int> row(h),column(w);
    rep(i,h){
        int tmp = 0;
        rep(j,w)tmp += field[i][j];
        row[i] = tmp;
    }
    rep(i,w){
        int tmp = 0;
        rep(j,h)tmp += field[j][i];
        column[i] = tmp;
    }
    
    rep(i,h){
        rep(j,w){
            cout << row[i] + column[j] - field[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}