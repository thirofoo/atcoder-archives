/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc353/submissions/53338835
 * Submitted at: 2024-05-11 21:17:05
 * Problem URL: https://atcoder.jp/contests/abc353/tasks/abc353_c
 * Result: AC
 * Execution Time: 47 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    vector<ll> a(n);
    ll mod = 100000000;
    ll ans = 0;
    rep(i, n) {
        cin >> a[i];
        ans += a[i] * (n-1);
    }
    sort(a.begin(), a.end());
    vector<ll> tmp = {a[0]};
    reps(i,1,n) {
        auto itr = lower_bound(tmp.begin(), tmp.end(), mod-a[i]);
        ans -= (i - (itr - tmp.begin())) * mod;
        tmp.emplace_back(a[i]);
    }
    cout << ans << endl;
    
    return 0;
}