/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/28915700
 * Submitted at: 2022-01-30 21:17:04
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_b
 * Result: AC
 * Execution Time: 185 ms
 */


#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int h,w; cin >> h >> w;
    vector<vector<int>> gyo(h,vector<int>(w));
    rep(i,h)rep(j,w)cin >> gyo[i][j];
    rep(i,w){
        rep(j,h){
            cout << gyo[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}