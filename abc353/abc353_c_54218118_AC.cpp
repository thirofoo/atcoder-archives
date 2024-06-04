/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc353/submissions/54218118
 * Submitted at: 2024-06-04 13:32:09
 * Problem URL: https://atcoder.jp/contests/abc353/tasks/abc353_c
 * Result: AC
 * Execution Time: 43 ms
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
    
    ll mod = 100000000;
    ll n, ans = 0; cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        ans += a[i];
    }
    ans *= n-1;
    sort(a.begin(), a.end());
    rep(i, n) {
        ll num = (a.end() - lower_bound(a.begin()+i+1, a.end(), mod-a[i]));
        ans -= mod * num;
    }
    cout << ans << endl;
    
    return 0;
}