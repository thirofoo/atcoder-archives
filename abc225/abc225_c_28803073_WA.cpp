/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc225/submissions/28803073
 * Submitted at: 2022-01-26 11:27:14
 * Problem URL: https://atcoder.jp/contests/abc225/tasks/abc225_c
 * Result: WA
 * Execution Time: 33 ms
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
    int n,m; cin >> n >> m;
    vector<vector<int>> num(n,vector<int>(m));
    rep(i,n)rep(j,m)cin >> num[i][j];
    for(int i=1;i<m;i++)if(num[0][i] != num[0][i-1]+1)return cout << "No" << endl,0;
    for(int i=1;i<n;i++){
        rep(j,m){
            if(!j && num[i][j] == num[i-1][j]+7)continue;
            if(j && num[i][j] == num[i][j-1]+1)continue;
            return cout << "No" << endl,0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}