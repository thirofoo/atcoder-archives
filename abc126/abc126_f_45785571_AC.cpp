/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc126/submissions/45785571
 * Submitted at: 2023-09-22 12:23:31
 * Problem URL: https://atcoder.jp/contests/abc126/tasks/abc126_f
 * Result: AC
 * Execution Time: 17 ms
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
    
    ll m, k; cin >> m >> k;
    // 1~2^m-1 の 総xor = 0 より k = 0~2^m-1 であれば基本いけそう
    if( m == 1 ) {
        if( k == 0 ) cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }
    if( pow(2,m) <= k ) return cout << -1 << endl, 0;
    vector<ll> ans;
    rep(i,pow(2,m)) {
        if( i == k ) continue;
        ans.emplace_back(i);
    }
    ans.emplace_back(k);
    for(int i=pow(2,m)-2;i>=0;i--) ans.emplace_back(ans[i]);
    ans.emplace_back(k);
    rep(i,ans.size()) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}