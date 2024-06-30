/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc360/submissions/55062459
 * Submitted at: 2024-06-30 21:18:33
 * Problem URL: https://atcoder.jp/contests/abc360/tasks/abc360_d
 * Result: AC
 * Execution Time: 35 ms
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
    
    ll n, t; cin >> n >> t;
    string s; cin >> s;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    vector<ll> ant1, ant2;
    rep(i, n) {
        if(s[i] == '1') ant1.emplace_back(x[i]);
        else ant2.emplace_back(x[i]);
    }
    sort(ant1.begin(), ant1.end());
    sort(ant2.begin(), ant2.end());
    ll ans = 0;
    rep(i, ant1.size()) {
        auto itr1 = lower_bound(ant2.begin(), ant2.end(), ant1[i]);
        auto itr2 = upper_bound(ant2.begin(), ant2.end(), ant1[i]+2*t);
        ans += itr2 - itr1;
    }
    cout << ans << '\n';
    
    return 0;
}