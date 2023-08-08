/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc203/submissions/44377803
 * Submitted at: 2023-08-08 12:13:56
 * Problem URL: https://atcoder.jp/contests/abc203/tasks/abc203_d
 * Result: AC
 * Execution Time: 208 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC 天才
    // 二次元累積和で中央値がX以下にすることが可能かを求める
    ll n,k; cin >> n >> k;
    vector<vector<ll>> a(n,vector<ll>(n)), r;
    rep(i,n)rep(j,n) cin >> a[i][j];

    ll left = -1, right = 1e16;
    while( right-left > 1 ) {
        ll mid = (right+left)/2;
        r.assign(n+1,vector<ll>(n+1,0));

        // mid以下のマスの数で中央値が mid を取れるか判定
        rep(i,n)rep(j,n) if(a[i][j] <= mid) r[i+1][j+1]++;
        rep(i,n+1)rep(j,n) r[i][j+1] += r[i][j];
        rep(i,n)rep(j,n+1) r[i+1][j] += r[i][j];

        ll max_num = 0;
        rep(i,n-k+1)rep(j,n-k+1) max_num = max(max_num, r[i+k][j+k] - r[i][j+k] - r[i+k][j] + r[i][j]);
        if( max_num >= k*k/2 + k%2 ) right = mid;
        else left = mid;
    }
    cout << right << endl;
    
    return 0;
}