/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc115/submissions/33219969
 * Submitted at: 2022-07-14 19:34:35
 * Problem URL: https://atcoder.jp/contests/arc115/tasks/arc115_b
 * Result: AC
 * Execution Time: 33 ms
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
    vector<vector<int>> c(n,vector<int>(n));
    rep(i,n)rep(j,n)cin >> c[i][j];
    vector<int> a(n),b(n);
    int m = c[0][0];
    rep(j,n)m = min(c[j][0],m);
    rep(j,n)a[j] = c[j][0]-m;
    rep(j,n){
        rep(k,n)m = min(c[k][j],m);
        rep(k,n){
            if(a[k] != c[k][j]-m)return cout << "No" << endl,0; 
        }
        m = INT_MAX;
    }

    cout << "Yes" << endl;
    rep(i,n)cout << a[i] << " ";
    cout << endl;
    rep(i,n)cout << c[i][i] - a[i] << " ";
    cout << endl;
    
    return 0;
}