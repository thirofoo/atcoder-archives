/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/32206815
 * Submitted at: 2022-06-04 21:05:22
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_b
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
    
    int n; cin >> n;
    vector<vector<int>> t(n,vector<int>(n,0));
    rep(i,n){
        for(int j=0;j<=i;j++){
            if(j == 0 || j == i)t[i][j] = 1;
            else t[i][j] = t[i-1][j-1] + t[i-1][j];
        }
    }
    rep(i,n){
        for(int j=0;j<=i;j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}