/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc359/submissions/54856877
 * Submitted at: 2024-06-23 00:46:11
 * Problem URL: https://atcoder.jp/contests/abc359/tasks/abc359_e
 * Result: AC
 * Execution Time: 26 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // Segment Tree でなくても stack で管理出来る。天才。
    ll n; cin >> n;
    vector<ll> h(n), th;
    rep(i, n) cin >> h[i];

    stack<P> st;
    st.push({INF, 0});
    vector<ll> dp(n+1, 0);
    reps(i, 1, n+1) {
        while(true) {
            auto [ch, idx] = st.top();
            if(ch <= h[i-1]) {
                st.pop();
                continue;
            }
            dp[i] = (i-idx) * h[i-1] + dp[idx] + (idx != 0 ? 0 : 1);
            st.push({h[i-1], i});
            break;
        }
    }
    reps(i, 1, n+1) cout << dp[i] << ' ';
    cout << '\n';
    
    return 0;
}