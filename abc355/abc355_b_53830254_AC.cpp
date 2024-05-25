/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc355/submissions/53830254
 * Submitted at: 2024-05-25 21:03:04
 * Problem URL: https://atcoder.jp/contests/abc355/tasks/abc355_b
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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m), c;
    set<ll> sa, sb;
    rep(i, n) {
        cin >> a[i];
        sa.insert(a[i]);
        c.emplace_back(a[i]);
    }
    rep(i, m) {
        cin >> b[i];
        sb.insert(b[i]);
        c.emplace_back(b[i]);
    }
    sort(c.begin(), c.end());
    rep(i,n+m-1) {
        if( sa.count(c[i]) && sa.count(c[i+1]) ) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}