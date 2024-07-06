/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc361/submissions/55262228
 * Submitted at: 2024-07-06 21:08:52
 * Problem URL: https://atcoder.jp/contests/abc361/tasks/abc361_c
 * Result: AC
 * Execution Time: 27 ms
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    deque<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    // 左から何個消すか全探索
    ll ans = INF;
    rep(i, k+1) ans = min(ans, a[n-1-(k-i)]-a[i]);
    cout << ans << endl;
    
    return 0;
}