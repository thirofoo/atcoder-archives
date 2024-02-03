/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/49935909
 * Submitted at: 2024-02-03 21:26:42
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_e
 * Result: WA
 * Execution Time: 1037 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

//セグ木状に乗せる型。
using S = ll;
S op(S a,S b){return max(a,b);} // operator(作用素)
S e(){return 0;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, d; cin >> n >> d;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // sg[i] : 過去iが出た時の最大長
    segtree<S, op, e> sg(500005);
    vector<ll> dp(n, 0);
    rep(i,n) {
        dp[i] = sg.prod(max(a[i]-d,0LL), min(a[i]+d+1,500005LL)) + 1;
        sg.set(a[i], max(dp[i], sg.get(a[i])));
        cerr << dp[i] << " ";
    }
    cerr << endl;
    cout << dp[n-1] << endl;
    
    return 0;
}