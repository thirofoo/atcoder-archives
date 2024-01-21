/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc170/submissions/49557888
 * Submitted at: 2024-01-21 22:47:30
 * Problem URL: https://atcoder.jp/contests/arc170/tasks/arc170_b
 * Result: AC
 * Execution Time: 399 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    vector<deque<ll>> dq(15);
    rep(i,n) {
        cin >> a[i];
        dq[a[i]].emplace_back(i);
    }
    // 等差全探索 ?
    // 左端全探索して、それより右のもののうち一番←にある 3 項の等差数列を探す
    ll ans = 0;
    rep(l,n) {
        ll cand = 1e9;
        for(ll d=-10; d<=10; d++) {
            for(ll a1=1; a1<=10; a1++) {
                ll a2 = a1 + d;
                ll a3 = a2 + d;
                if( a2 <= 0 || 10 < a2 || a3 <= 0 || 10 < a3 ) continue;
                auto it1 = lower_bound(dq[a1].begin(), dq[a1].end(), l);
                if( it1 == dq[a1].end() ) continue;
                auto it2 = upper_bound(dq[a2].begin(), dq[a2].end(), *it1);
                if( it2 == dq[a2].end() ) continue;
                auto it3 = upper_bound(dq[a3].begin(), dq[a3].end(), *it2);
                if( it3 == dq[a3].end() ) continue;
                cand = min(cand, *it3);
                // cerr << a1 << " " << a2 << " " << a3 << endl;
            }
        }
        if( cand != 1e9 ) ans += n-cand;
        dq[a[l]].pop_front();
        // cerr << "ans: " << ans << endl;
        // cerr << "cand: " << cand << endl << endl;
    }
    cout << ans << endl;
    
    return 0;
}