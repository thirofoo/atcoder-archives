/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/50525629
 * Submitted at: 2024-02-23 11:39:24
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_d
 * Result: AC
 * Execution Time: 14 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n), cnt(200005,0);
    rep(i,n) cin >> a[i], cnt[a[i]]++;
    auto nC2 = [](ll n){return n*(n-1)/2;};
    auto nC3 = [](ll n){return n*(n-1)*(n-2)/6;};
    ll ans = nC3(n);
    rep(i,200005) ans -= nC2(cnt[i])*(n-cnt[i]) + nC3(cnt[i]);
    cout << ans << endl;
    
    return 0;
}