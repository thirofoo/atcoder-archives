/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc225/submissions/28803273
 * Submitted at: 2022-01-26 11:45:40
 * Problem URL: https://atcoder.jp/contests/abc225/tasks/abc225_c
 * Result: WA
 * Execution Time: 34 ms
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
    vector<vector<ll>> num(n,vector<ll>(m));
    rep(i,n)rep(j,m)cin >> num[i][j];
    if(num[0][0]%7 != 1)return cout << "No" << endl,0;
    for(int i=1;i<m;i++)if(num[0][i] != num[0][i-1]+1)return cout << "No" << endl,0;
    for(int i=1;i<n;i++){
        rep(j,m){
            if(num[i][j] != num[i-1][j]+7)return cout << "No" << endl,0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}