/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc178/submissions/53669926
 * Submitted at: 2024-05-19 21:13:28
 * Problem URL: https://atcoder.jp/contests/arc178/tasks/arc178_a
 * Result: AC
 * Execution Time: 82 ms
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
    vector<ll> a(m);
    rep(i,m) cin >> a[i];
    set<ll> st;
    rep(i,m) {
        if( a[i] == 1 || a[i] == n ) {
            cout << -1 << endl;
            return 0;
        }
        st.insert(a[i]);
    }
    ll start = -1, cnt = 0;
    reps(i, 1, n+1) {
        if( st.count(i) ) {
            if( cnt == 0 ) start = i;
            cnt++;
        }
        else {
            if( start != -1 ) {
                reps(j, start+1, start+cnt+1) cout << j << " ";
                cout << start << " ";
                start = -1;
                cnt = 0;
            }
            else cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}