/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc263/submissions/47068373
 * Submitted at: 2023-10-29 20:24:11
 * Problem URL: https://atcoder.jp/contests/abc263/tasks/abc263_e
 * Result: AC
 * Execution Time: 81 ms
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
    vector<ll> a(n-1);
    rep(i,n-1) cin >> a[i];
    segtree<S,op,e> dp(n);
    for(int i=n-2; i>=0; i--) dp.set(i, (dp.prod(i+1, min(n,i+a[i]+1)) / (a[i]+1) + 1) * (a[i]+1) / a[i] );
    cout << dp.get(0).val() << endl;
    
    return 0;
}