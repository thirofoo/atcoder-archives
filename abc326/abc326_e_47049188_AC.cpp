/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/47049188
 * Submitted at: 2023-10-29 01:22:49
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
    segtree<S,op,e> sg(n+1);
    sg.set(0,1);
    rep(i,n) sg.set(i+1, sg.prod(0,i+1) / n );
    mint ans = 0;
    rep(i,n) ans += sg.get(i+1) * a[i];
    cout << ans.val() << endl;
    
    return 0;
}