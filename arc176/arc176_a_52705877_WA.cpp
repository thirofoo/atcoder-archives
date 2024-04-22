/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc176/submissions/52705877
 * Submitted at: 2024-04-23 08:46:39
 * Problem URL: https://atcoder.jp/contests/arc176/tasks/arc176_a
 * Result: WA
 * Execution Time: 1109 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> row_cnt(n, 0), col_cnt(n, 0);
    vector<ll> a(m), b(m);
    set<P> st;
    rep(i,m)  {
        cin >> a[i] >> b[i]; a[i]--; b[i]--;
        row_cnt[a[i]]++;
        col_cnt[b[i]]++;
        st.emplace(a[i], b[i]);
    }
    queue<ll> cand;
    rep(i,n) if( col_cnt[i] < m ) cand.push(i);

    vector<P> ans;
    rep(i,m) ans.emplace_back(P(a[i], b[i]));
    rep(i,n) {
        while( row_cnt[i] < m ) {
            ll num = cand.front(); cand.pop();
            if( st.count(P(i, num)) ) {
                cand.push(num);
                continue;
            }
            ans.emplace_back(P(i, num));
            col_cnt[num]++;
            row_cnt[i]++;
            if( col_cnt[num] < m ) cand.push(num);
        }
    }

    // vector<ll> rc(n,0), cc(n,0);
    // for( auto [x, y] : ans ) {
    //     rc[x]++;
    //     cc[y]++;
    // }
    // rep(i,n) cerr << rc[i] << " ";
    // cerr << endl;
    // rep(i,n) cerr << cc[i] << " ";
    // cerr << endl;

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << endl;
    for( auto [x, y] : ans ) cout << x+1 << " " << y+1 << endl;
    
    return 0;
}