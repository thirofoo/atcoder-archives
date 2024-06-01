/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc356/submissions/54098165
 * Submitted at: 2024-06-01 21:21:28
 * Problem URL: https://atcoder.jp/contests/abc356/tasks/abc356_d
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
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<ll> r(60, 1);
    reps(i, 1, 60) r[i] = r[i-1] * 2;

    mint ans = 0;
    rep(i,60) {
        if( !(m & (1LL << i)) ) continue;
        ll rest = n - (r[i] - 1);
        if( rest < 0 ) break;

        ll syo = rest / (r[i]*2);
        ll amari = rest % (r[i]*2);
        ans += syo * r[i];
        ans += min(r[i], amari);
    }
    cout << ans.val() << endl;
    
    return 0;
}