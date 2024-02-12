/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/50217963
 * Submitted at: 2024-02-12 10:58:23
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_e
 * Result: AC
 * Execution Time: 31 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    if( k == 1 ) return cout << "Infinity" << endl, 0;
    // 直線の候補は O(N^2), それぞれで各頂点確認 O(N) ⇒ O(N^3)
    ll ans = 0;
    set<T> lines;
    rep(i,n) reps(j,i+1,n) {
        ll dx = x[i] - x[j];
        ll dy = y[i] - y[j];
        ll c = dx*y[i] - dy*x[i];

        // 直線の方程式の形式統一
        ll gcd = euclid(dy, euclid(dx, c));
        dx /= gcd, dy /= gcd, c /= gcd;
        lines.insert(T(dx, dy, c));
    }
    for(auto &&[dx, dy, c]: lines) {
        ll cnt = 0;
        rep(k,n) cnt += (dy*x[k] - dx*y[k] + c == 0);
        ans += (cnt >= k);
    }
    cout << ans << endl;
    
    return 0;
}