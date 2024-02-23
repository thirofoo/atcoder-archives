/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/50525170
 * Submitted at: 2024-02-23 11:07:53
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_d
 * Result: AC
 * Execution Time: 13 ms
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
    
    // 解説 : A_i, A_j, A_k が相異なる ⇔ 昇順の組み合わせと1対1対応
    ll n; cin >> n;
    ll upper = 200005;
    vector<ll> cnt(upper, 0);
    rep(i, n) {
        ll a; cin >> a;
        cnt[a]++;
    }
    reps(i,1,upper) cnt[i] += cnt[i-1];
    ll ans = 0;
    reps(i,1,upper) ans += cnt[i-1] * (cnt[upper-1]-cnt[i]) * (cnt[i]-cnt[i-1]);
    cout << ans << endl;
    
    return 0;
}