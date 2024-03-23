/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc346/submissions/51575046
 * Submitted at: 2024-03-23 21:32:38
 * Problem URL: https://atcoder.jp/contests/abc346/tasks/abc346_e
 * Result: AC
 * Execution Time: 138 ms
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
    
    ll h, w, m; cin >> h >> w >> m;
    vector<ll> t(m), a(m), x(m);
    rep(i,m) {
        cin >> t[i] >> a[i] >> x[i];
        a[i]--;
    }
    // クエリ逆順
    vector<bool> row(h, false), col(w, false);
    reverse(t.begin(), t.end());
    reverse(a.begin(), a.end());
    reverse(x.begin(), x.end());
    vector<ll> ans(200005, 0);
    ll row_cnt = 0, col_cnt = 0;
    rep(i,m) {
        if( t[i] == 1 ) {
            if( row[a[i]] ) continue;
            ans[x[i]] += w - col_cnt;
            row[a[i]] = true;
            row_cnt++;
        }
        else {
            if( col[a[i]] ) continue;
            ans[x[i]] += h - row_cnt;
            col[a[i]] = true;
            col_cnt++;
        }
    }
    vector<P> answer;
    // 塗られてない場所は 0
    ans[0] += (h - row_cnt) * (w - col_cnt);
    rep(i,200005) {
        if( ans[i] == 0 ) continue;
        answer.push_back({i, ans[i]});
    }
    cout << answer.size() << endl;
    for(auto p : answer) cout << p.first << " " << p.second << endl;
    
    return 0;
}