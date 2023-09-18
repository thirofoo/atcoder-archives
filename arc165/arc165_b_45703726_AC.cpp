/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc165/submissions/45703726
 * Submitted at: 2023-09-18 17:53:11
 * Problem URL: https://atcoder.jp/contests/arc165/tasks/arc165_b
 * Result: AC
 * Execution Time: 71 ms
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
    
    ll n, k; cin >> n >> k;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    // 操作を行って大きくなることはない
    // ⇒ 出来るだけ上位桁から昇順のままになるのが良い
    // ⇒ 長さkの区間で上位から昇順になってる個数 + 自分より上の桁の個数 が max の時が答え
    set<ll> st;
    rep(i,k) st.insert(p[i]);
    ll ans = -1, idx = 0;
    for(ll i=0;i<=n-k;i++) {
        if( i >= ans ) {
            auto itr = st.begin();
            ll cand = 0;
            rep(j,k) {
                if( (*itr) == p[i+j] ) cand++;
                else break;
                itr++;
            }
            if( cand == k ) {
                rep(i,n) cout << p[i] << " ";
                return 0;
            }
            if( ans < i+cand ) {
                ans = i+cand;
                idx = i;
            }
            if( i+k == n ) break;
        }
        st.erase(st.lower_bound(p[i]));
        st.insert(p[i+k]);
    }
    sort( p.begin()+idx, p.begin()+idx+k );
    rep(i,n) cout << p[i] << " ";
    cout << endl;
    
    return 0;
}