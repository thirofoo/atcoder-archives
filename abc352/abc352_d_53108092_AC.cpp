/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc352/submissions/53108092
 * Submitted at: 2024-05-04 21:21:49
 * Problem URL: https://atcoder.jp/contests/abc352/tasks/abc352_d
 * Result: AC
 * Execution Time: 81 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    
    ll n, k; cin >> n >> k;
    vector<ll> p(n), idx(n,0);
    rep(i,n) {
        cin >> p[i]; p[i]--;
        idx[p[i]] = i;
    }
    set<ll> st;
    rep(i,k) st.insert(idx[i]);
    ll ans = *st.rbegin() - *st.begin();
    reps(i,k,n) {
        st.erase(idx[i-k]);
        st.insert(idx[i]);
        ans = min(ans, *st.rbegin() - *st.begin());
    }
    cout << ans << '\n';
    
    return 0;
}