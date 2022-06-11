/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc255/submissions/32375519
 * Submitted at: 2022-06-11 21:02:39
 * Problem URL: https://atcoder.jp/contests/abc255/tasks/abc255_a
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    vector<vector<int>> s(2,vector<int>(2,0));
    int r,c; cin >> r >> c;
    rep(i,2){
        rep(j,2){
            cin >> s[i][j];
        }
    }
    cout << s[r-1][c-1] << endl;

    return 0;
}