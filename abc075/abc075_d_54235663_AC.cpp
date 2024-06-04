/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc075/submissions/54235663
 * Submitted at: 2024-06-05 00:55:30
 * Problem URL: https://atcoder.jp/contests/abc075/tasks/abc075_d
 * Result: AC
 * Execution Time: 262 ms
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
    
    // N ≦ 50 なら O(N^5) でもAC
    ll n, k; cin >> n >> k;
    vector<P> v;
    rep(i,n) {
        ll tx, ty; cin >> tx >> ty;
        v.emplace_back(P(tx, ty));
    }
    ll ans = INF;
    for(auto &&[x1,_]:v) for(auto &&[x2,_]:v) {
        for(auto &&[_,y1]:v) for(auto &&[_,y2]:v) {
            ll cnt = 0;
            for(auto &&[x,y]:v) {
                if(x1 <= x && x <= x2 && y1 <= y && y <= y2) cnt++;
            }
            if(cnt >= k) ans = min(ans, (x2-x1)*(y2-y1));
        }
    }
    cout << ans << endl;
    
    return 0;
}