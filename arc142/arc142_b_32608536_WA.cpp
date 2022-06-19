/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc142/submissions/32608536
 * Submitted at: 2022-06-19 22:55:34
 * Problem URL: https://atcoder.jp/contests/arc142/tasks/arc142_b
 * Result: WA
 * Execution Time: 31 ms
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
    
    int n,now = 1; cin >> n;
    vector<vector<int>> ans(n,vector<int>(n,0));
    
    for(int i=0;i<n/2;i++){
        if(i%2 == 0){
            for(int j=i;j<n-i-1;j++)ans[i][j] = now++;
            for(int j=i;j<n-i-1;j++)ans[j][n-1-i] = now++;
            for(int j=i;j<n-i-1;j++)ans[n-1-i][n-1-j] = now++;
            for(int j=i;j<n-i-1;j++)ans[n-1-j][i] = now++;
        }
    }
    for(int i=0;i<n/2;i++){
        if(i%2 == 1){
            for(int j=i;j<n-i-1;j++)ans[i][j] = now++;
            for(int j=i;j<n-i-1;j++)ans[j][n-1-i] = now++;
            for(int j=i;j<n-i-1;j++)ans[n-1-i][n-1-j] = now++;
            for(int j=i;j<n-i-1;j++)ans[n-1-j][i] = now++;
        }
    }
    if(n%2){
        ans[n/2][n/2] = now;
        swap(ans[n/2][n/2-1],ans[n/2+1][n/2-1]);
    }

    rep(i,n){
        rep(j,n){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}