/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55523487
 * Submitted at: 2024-07-13 21:09:57
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_b
 * Result: AC
 * Execution Time: 1 ms
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

    vector<ll> x(3), y(3);
    rep(i, 3) cin >> x[i] >> y[i];
    rep(i, 3) for(int j = i + 1; j < 3; j++) {
        ll k = 3 - i - j;
        ll dis1 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        ll dis2 = (x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k]);
        ll dis3 = (x[k] - x[i]) * (x[k] - x[i]) + (y[k] - y[i]) * (y[k] - y[i]);
        if(dis1 == dis2 + dis3)
            return cout << "Yes" << endl, 0;
        else if(dis2 == dis1 + dis3)
            return cout << "Yes" << endl, 0;
        else if(dis3 == dis1 + dis2)
            return cout << "Yes" << endl, 0;
    }
    cout << "No" << endl;

    return 0;
}