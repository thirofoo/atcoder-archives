/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc354/submissions/53591586
 * Submitted at: 2024-05-18 21:08:18
 * Problem URL: https://atcoder.jp/contests/abc354/tasks/abc354_b
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll n; cin >> n;
    vector<pair<string, ll>> s;
    ll total = 0;
    rep(i, n) {
        string t; ll c; cin >> t >> c;
        s.push_back({t, c});
        total += c;
    }
    sort(s.begin(), s.end(), [](pair<string, ll> a, pair<string, ll> b) {
        // 辞書順
        auto [sa, ca] = a;
        auto [sb, cb] = b;
        rep(i, min(sa.size(), sb.size())) {
            if(sa[i] != sb[i]) return sa[i] < sb[i];
        }
        return sa.size() < sb.size();
    });
    auto [ans, _] = s[total%n];
    cout << ans << endl;
    
    return 0;
}