/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/54269521
 * Submitted at: 2024-06-06 15:46:31
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_e
 * Result: WA
 * Execution Time: 362 ms
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
    
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<P> lr;
        set<ll> mex;
        rep(i,n) {
            ll l, r; cin >> l >> r;
            lr.emplace_back(P{l, r});
            mex.insert(l);
        }
        sort(lr.begin(), lr.end(), [](P a, P b) {
            // 区間スケジューリングっぽい順序の方が良さそう…？
            auto [l1, r1] = a;
            auto [l2, r2] = b;
            if(r1 != r2) return r1 < r2;
            return l1 > l2;
        });

        ll ans = 0;
        map<ll, ll> mp;
        bool ok = true;
        rep(i,n) {
            auto [l, r] = lr[i];
            auto itr = mex.lower_bound(l);
            ll v = *itr;
            if(v > r) {
                ok = false;
                break;
            }
            mex.erase(itr);
            mp[v] = mp[v+1] + 1;
            mex.insert(v + mp[v]);
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    
    return 0;
}