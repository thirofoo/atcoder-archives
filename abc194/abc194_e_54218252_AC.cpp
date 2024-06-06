/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc194/submissions/54218252
 * Submitted at: 2024-06-04 13:39:03
 * Problem URL: https://atcoder.jp/contests/abc194/tasks/abc194_e
 * Result: AC
 * Execution Time: 1649 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    set<ll> st;
    vector<ll> cnt(n+1, 0);
    rep(i,n+1) st.insert(i);
    rep(i, n) {
        cin >> a[i];
        if(i < m) {
            if( cnt[a[i]] == 0 ) {
                st.erase(a[i]);
            }
            cnt[a[i]]++;
        }
    }
    ll ans = *st.begin();
    reps(i, m, n) {
        if( cnt[a[i-m]] == 1 ) {
            st.insert(a[i-m]);
        }
        cnt[a[i-m]]--;
        if( cnt[a[i]] == 0 ) {
            st.erase(a[i]);
        }
        cnt[a[i]]++;
        ans = min(ans, *st.begin());
    }
    cout << ans << endl;
    
    return 0;
}