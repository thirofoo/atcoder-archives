/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc072/submissions/50436379
 * Submitted at: 2024-02-19 09:35:48
 * Problem URL: https://atcoder.jp/contests/abc072/tasks/arc082_b
 * Result: WA
 * Execution Time: 7 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> p(n), idx;
    rep(i,n) {
        cin >> p[i];
        if( p[i] == i+1 ) idx.emplace_back(i);
    }

    ll ans = 1e9, cand = 0, size = idx.size();
    for(ll i=0; i<size-1; i+=2) cand += abs(idx[i+1]-idx[i]);
    if( size%2 == 1 ) cand++;
    ans = min(cand, ans);
    cand = 0;
    reverse(idx.begin(), idx.end());
    for(ll i=0; i<size-1; i+=2) cand += abs(idx[i+1]-idx[i]);
    if( size%2 == 1 ) cand++;
    ans = min(cand, ans);
    cout << ans << '\n';
    
    return 0;
}