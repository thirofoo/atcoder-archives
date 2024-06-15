/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc358/submissions/54572955
 * Submitted at: 2024-06-15 21:14:25
 * Problem URL: https://atcoder.jp/contests/abc358/tasks/abc358_d
 * Result: AC
 * Execution Time: 63 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    vector<P> c;
    rep(i, n) {
        cin >> a[i];
        c.emplace_back(P(a[i], 1));
    }
    rep(i, m) {
        cin >> b[i];
        c.emplace_back(P(b[i], 0));
    }
    ll ans = 0;
    stack<ll> st;
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    rep(i, c.size()) {
        auto [v, type] = c[i];
        if(type == 1) {
            st.push(v);
        }
        else {
            if(st.empty()) {
                cout << -1 << endl;
                return 0;
            }
            ans += st.top();
            st.pop();
        }
    }
    cout << ans << endl;
    
    return 0;
}