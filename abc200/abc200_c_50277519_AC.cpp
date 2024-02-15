/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc200/submissions/50277519
 * Submitted at: 2024-02-15 10:04:04
 * Problem URL: https://atcoder.jp/contests/abc200/tasks/abc200_c
 * Result: AC
 * Execution Time: 12 ms
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
    vector<ll> a(n), cnt(205,0);
    rep(i,n) {
        cin >> a[i];
        a[i] %= 200;
        cnt[a[i]]++;
    }
    ll ans = 0;
    rep(i,200) ans += cnt[i] * (cnt[i] - 1) / 2;
    cout << ans << endl;
    
    return 0;
}