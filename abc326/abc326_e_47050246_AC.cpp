/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/47050246
 * Submitted at: 2023-10-29 02:36:47
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_e
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
S e(){return mint(0);} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    segtree<S,op,e> dp(n+1);
    for(int i=n-1; i>=0; i--) dp.set(i, a[i] + dp.prod(i+1,n)/n);
    cout << (dp.all_prod()/n).val() << endl;
    
    return 0;
}