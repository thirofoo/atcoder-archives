/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc176/submissions/52655435
 * Submitted at: 2024-04-21 21:09:02
 * Problem URL: https://atcoder.jp/contests/arc176/tasks/arc176_a
 * Result: WA
 * Execution Time: 998 ms
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
    rep(i,m)  {
        cin >> a[i] >> b[i]; a[i]--; b[i]--;
        row_cnt[a[i]]++;
        col_cnt[b[i]]++;
    }
    queue<ll> cand;
    rep(i,n) if( col_cnt[i] < m ) cand.push(i);
    cout << m*n << endl;
    rep(i,m) cout << a[i]+1 << " " << b[i]+1 << endl;
    rep(i,n) {
        while( row_cnt[i] < m ) {
            ll num = cand.front(); cand.pop();
            cout << i+1 << " " << num+1 << endl;
            col_cnt[num]++;
            row_cnt[i]++;
            if( col_cnt[num] < m ) cand.push(num);
        }
    }
    
    return 0;
}