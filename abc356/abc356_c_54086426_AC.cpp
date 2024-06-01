/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc356/submissions/54086426
 * Submitted at: 2024-06-01 21:08:08
 * Problem URL: https://atcoder.jp/contests/abc356/tasks/abc356_c
 * Result: AC
 * Execution Time: 28 ms
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
    
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> a;
    vector<char> r(m);
    rep(i,m) {
        ll c; cin >> c;
        vector<ll> ta(c);
        rep(j, c) {
            cin >> ta[j];
            ta[j]--;
        }
        a.emplace_back(ta);
        cin >> r[i];
    }
    ll ans = 0;
    rep(i, (1LL << n)) {
        bool f = true;
        rep(j,m) {
            ll cnt = 0;
            for(auto x : a[j]) if( i & (1LL << x) ) cnt++;
            if( (r[j] == 'o' && cnt < k) || (r[j] == 'x' && cnt >= k) ) {
                f = false;
                break;
            }
        }
        if( f ) ans++;
    }
    cout << ans << '\n';
    
    return 0;
}