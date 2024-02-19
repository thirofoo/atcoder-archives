/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc072/submissions/50436302
 * Submitted at: 2024-02-19 09:28:33
 * Problem URL: https://atcoder.jp/contests/abc072/tasks/arc082_b
 * Result: WA
 * Execution Time: 6 ms
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
    rep(i,n) cin >> p[i];
    ll ans = 1e9, cand = 0;
    rep(i,n-1) if( p[i] == i+1 ) idx.emplace_back(i);
    if( idx.empty() ) {
        cout << 0 << '\n';
        return 0;
    }

    for(ll i=0; i<idx.size()-1; i+=2) cand += (idx[i+1]-idx[i]);
    if( idx.size()%2 == 1 ) cand++;
    ans = min(cand, ans);
    cand = 0;
    for(ll i=idx.size()-1; i>0; i-=2) cand += (idx[i]-idx[i+1]);
    if( idx.size()%2 == 1 ) cand++;
    ans = min(cand, ans);
    cout << ans << '\n';
    
    return 0;
}