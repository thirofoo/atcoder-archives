/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc224/submissions/28825808
 * Submitted at: 2022-01-27 20:20:37
 * Problem URL: https://atcoder.jp/contests/abc224/tasks/abc224_b
 * Result: AC
 * Execution Time: 8 ms
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
    vector<vector<int>> num(h,vector<int>(w));
    rep(i,h)rep(j,w)cin >> num[i][j];
    rep(i,h-1){
        for(int j=i+1;j<h;j++){
            rep(k,w-1){
                for(int l=k+1;l<w;l++){
                    if(num[i][k]+num[j][l] > num[j][k]+num[i][l])return cout << "No" << endl,0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}