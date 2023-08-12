/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc058/submissions/44539350
 * Submitted at: 2023-08-12 23:48:44
 * Problem URL: https://atcoder.jp/contests/abc058/tasks/arc071_b
 * Result: AC
 * Execution Time: 34 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC 立式して各要素ごとに考える (主客転倒)
    ll n,m; cin >> n >> m;
    vector<ll> x(n), y(m);
    rep(i,n) cin >> x[i];
    rep(i,m) cin >> y[i];
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    mint ans1 = 0, ans2;
    rep(i,n) ans1 += x[i] * (i - (n-(i+1)));
    rep(i,m) ans2 += y[i] * (i - (m-(i+1)));
    cout << (ans1*ans2).val() << endl;
    
    return 0;
}