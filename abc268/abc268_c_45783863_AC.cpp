/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc268/submissions/45783863
 * Submitted at: 2023-09-22 09:54:06
 * Problem URL: https://atcoder.jp/contests/abc268/tasks/abc268_c
 * Result: AC
 * Execution Time: 15 ms
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
    
    ll n; cin >> n;
    vector<ll> p(n), cnt(n,0);
    rep(i,n) {
        cin >> p[i];
        cnt[(p[i]-i+n)%n]++;
    }
    // 適正との距離が -1~+1 にあるものの最大値
    ll ans = -1;
    rep(i,n) {
        ll cand = 0;
        rep(j,3) cand += cnt[(i+j)%n];
        ans = max(ans,cand);
    }
    cout << ans << endl;
    
    return 0;
}