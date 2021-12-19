/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc232/submissions/28005212
 * Submitted at: 2021-12-19 21:43:17
 * Problem URL: https://atcoder.jp/contests/abc232/tasks/abc232_d
 * Result: WA
 * Execution Time: 11 ms
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
    int h,w;
    cin >> h >> w;
    vector<vector<char>> map(h,vector<char>(w));
    rep(i,h)rep(j,w)cin >> map[i][j];
    vector<vector<int>> ans(h,vector<int>(w,0));
    ans[0][0] = 1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j] == '#')continue;
            if(j+1 < w && map[i][j+1] == '.')ans[i][j+1] = ans[i][j] + 1;
            if(i+1 < h && map[i+1][j] == '.')ans[i+1][j] = ans[i][j] + 1;
        }
    }
    int answer = 0;
    rep(i,h){
        rep(j,w){
            cout << ans[i][j] << " ";
            answer = max(answer,ans[i][j]);
        }
        cout << endl;
    }
    cout << answer << endl;
    return 0;
}