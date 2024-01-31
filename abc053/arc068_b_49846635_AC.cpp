/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc053/submissions/49846635
 * Submitted at: 2024-02-01 00:32:10
 * Problem URL: https://atcoder.jp/contests/abc053/tasks/arc068_b
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n), cnt(100005,0);
    rep(i,n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    // 実は上界達成可能 pattern っぽい
    ll ans = 0;
    rep(i,100005) ans += max(0ll, cnt[i]-1);
    cout << max(1ll, n-ans-ans%2) << endl;
    
    return 0;
}