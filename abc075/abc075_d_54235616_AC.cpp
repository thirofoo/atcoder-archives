/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc075/submissions/54235616
 * Submitted at: 2024-06-05 00:51:32
 * Problem URL: https://atcoder.jp/contests/abc075/tasks/abc075_d
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<P> v;
    rep(i,n) {
        ll tx, ty; cin >> tx >> ty;
        v.emplace_back(P(tx, ty));
    }
    sort(v.begin(), v.end());

    ll ans = INF;
    rep(i,n) {
        auto &&[x1, _] = v[i];
        reps(j,i+1,n) {
            auto &&[x2, _] = v[j];
            rep(l,n) {
                auto &&[x3, y3] = v[l];
                vector<ll> y;
                rep(m,n) {
                    auto &&[xm, ym] = v[m];
                    if(x1 <= xm && xm <= x2) {
                        y.emplace_back(ym);
                    }
                }
                sort(y.begin(), y.end());
                ll idx = lower_bound(y.begin(), y.end(), y3) - y.begin();
                if(idx + k - 1 >= y.size()) continue;
                ll y4 = y[idx + k - 1];
                ans = min(ans, (x2 - x1) * (y4 - y3));
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}