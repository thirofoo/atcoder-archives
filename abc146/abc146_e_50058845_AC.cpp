/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc146/submissions/50058845
 * Submitted at: 2024-02-06 19:30:07
 * Problem URL: https://atcoder.jp/contests/abc146/tasks/abc146_e
 * Result: AC
 * Execution Time: 89 ms
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
#define rep(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n+1,0);
    rep(i,0,n) {
        cin >> a[i+1];
        a[i+1] += a[i];
    }
    // [0 ~ r) として (要素総和-要素数)%k が一致する部分の数え上げっぽい？
    ll ans = 0;
    map<ll,ll> mp;
    mp[0]++;
    rep(r,1,n+1) {
        // ★ Point : 過去の期限が切れたものは消していく
        if( r-k >= 0 ) mp[(a[r-k]-(r-k))%k]--;
        ans += mp[(a[r]-r)%k];
        mp[(a[r]-r)%k]++;
    }
    cout << ans << endl;
    
    return 0;
}