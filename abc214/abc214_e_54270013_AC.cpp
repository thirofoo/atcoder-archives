/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/54270013
 * Submitted at: 2024-06-06 16:05:40
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_e
 * Result: AC
 * Execution Time: 243 ms
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
    
    // 解説 AC : 左端全探索 & 過去に出てきた区間のうち右端最初を詰める
    // - 左端全探索をすると TLE するが、過去に出てきた区間が全て消費したら、
    //   次に区間を追加する場所まで skip することでシミュレーション部分は O(N) になる

    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        set<ll> st;
        map<ll, vector<P>> lr;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll now = INF;
        rep(i,n) {
            ll l, r; cin >> l >> r;
            lr[l].emplace_back(P{l, r});
            now = min(now, l);
            st.insert(l);
        }
        bool ok = true;
        ll pop_cnt = 0;
        while(pop_cnt < n) {
            if(lr.count(now)) {
                for(auto [l, r] : lr[now]) {
                    pq.push(r);
                }
            }

            if(!pq.empty()) {
                ll r = pq.top(); pq.pop();
                if(r < now) {
                    ok = false;
                    break;
                }
                pop_cnt++;
                now++;
            } else {
                now = *st.upper_bound(now);
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    
    return 0;
}