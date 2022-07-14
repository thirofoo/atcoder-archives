/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/33218931
 * Submitted at: 2022-07-14 18:24:38
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_b
 * Result: AC
 * Execution Time: 8 ms
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
    
    int n; cin >> n;
    vector<vector<int>> ans(n,vector<int>(n+1,0));
    ans[0][0] = 0;
    ans[0][1] = 1;
    ans[0][2] = 0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=i+1;j++){
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    rep(i,n){
        rep(j,i+1){
            cout << ans[i][j+1] << " ";
        }
        cout << endl;
    }
    
    return 0;
}