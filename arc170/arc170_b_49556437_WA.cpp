/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc170/submissions/49556437
 * Submitted at: 2024-01-21 22:35:58
 * Problem URL: https://atcoder.jp/contests/arc170/tasks/arc170_b
 * Result: WA
 * Execution Time: 40 ms
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
                if( dq[a1].empty() || dq[a2].empty() || dq[a3].empty() ) continue;
                if( dq[a1].front() > dq[a2].front() || dq[a2].front() > dq[a3].front() ) continue;
                if( d == 0 && dq[a1].size() < 3 ) continue;
                cand = min(cand, max({dq[a1].front(), dq[a2].front(), dq[a3].front()}));
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