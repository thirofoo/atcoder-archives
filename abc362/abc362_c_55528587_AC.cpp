/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55528587
 * Submitted at: 2024-07-13 21:15:06
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_c
 * Result: AC
 * Execution Time: 36 ms
 */

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> l(n), r(n);
    ll max_sum = 0, min_sum = 0;
    rep(i, n) {
        cin >> l[i] >> r[i];
        max_sum += r[i];
        min_sum += l[i];
    }
    if(max_sum >= 0 && min_sum <= 0) {
        cout << "Yes" << endl;
        vector<ll> ans(n, 0);
        ll rest = max_sum;
        rep(i, n) {
            ans[i] = r[i];
            ans[i] -= min(r[i] - l[i], rest);
            rest -= min(r[i] - l[i], rest);
        }
        rep(i, n) cout << ans[i] << " ";
        cout << endl;
    } else
        cout << "No" << endl;

    return 0;
}