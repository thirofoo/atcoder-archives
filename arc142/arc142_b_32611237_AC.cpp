/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc142/submissions/32611237
 * Submitted at: 2022-06-19 23:46:43
 * Problem URL: https://atcoder.jp/contests/arc142/tasks/arc142_b
 * Result: AC
 * Execution Time: 28 ms
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

vector<int> dx = {-1,-1,-1,0,1,1,1,0};
vector<int> dy = {-1,0,1,1,1,0,-1,-1};

int n,now = 1;
// bool ok(vector<vector<int>>& ans){
//     rep(i,n){
//         rep(j,n){
//             int c1 = 0,c2 = 0;
//             rep(k,8){
//                 if(i+dx[k] < 0 || i+dx[k] >= n || j+dy[k] < 0 || j+dy[k] >= n)continue;
//                 if(ans[i][j] > ans[i+dx[k]][j+dy[k]])c1++;
//                 else c2++;
//             }
//             if(c1 == c2){
//                 cout << i << " " << j << endl;
//                 return false;
//             }
//         }
//     }
//     return true;
// }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
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
        swap(ans[n/2-1][n/2],ans[n/2-1][n/2L+1]);
    }

    // if(ok(ans))cout << "Yes" << endl;
    // else cout << "No" << endl;

    rep(i,n){
        rep(j,n){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}