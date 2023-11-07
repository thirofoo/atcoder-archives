/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/47356588
 * Submitted at: 2023-11-07 18:40:35
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_e
 * Result: AC
 * Execution Time: 82 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

//セグ木状に乗せる型。
using S = mint;
S op(S a,S b){return a+b;} // operator(作用素)
S e(){return 0;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n+1);
    rep(i,n) {
        cin >> a[i+1];
        a[i+1] += a[i];
    }
    segtree<S,op,e> dp(n+1);
    mint inv = mint{1} / n;
    // dp[i] : 目iが出た時の給料の期待値
    for(int i=n-1; i>=0; i--) dp.set(i,(a[n]-a[i]+dp.prod(i,n)) / n);
    cout << dp.get(0).val() << endl;
    
    return 0;
}