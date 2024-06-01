/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc356/submissions/54141398
 * Submitted at: 2024-06-02 02:03:49
 * Problem URL: https://atcoder.jp/contests/abc356/tasks/abc356_e
 * Result: AC
 * Execution Time: 160 ms
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
    
    // 解説AC : 商で全探索をすると調和級数に落ちる

    ll n; cin >> n;
    vector<ll> a(n), cnt(1e6+5, 0);
    rep(i,n) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll ans = 0;
    fenwick_tree<ll> fw(1e6+5);
    for(ll i=1e6; i>=1; i--) {
        if( !cnt[i] ) continue;
        for(ll j=i; j<=1e6; j+=i) ans += fw.sum(j, 1e6+5) * cnt[i];
        ans += cnt[i] * (cnt[i]-1) / 2;
        fw.add(i, cnt[i]);
    }
    cout << ans << endl;
    
    return 0;
}