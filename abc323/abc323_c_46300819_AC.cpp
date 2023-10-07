/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc323/submissions/46300819
 * Submitted at: 2023-10-07 21:18:02
 * Problem URL: https://atcoder.jp/contests/abc323/tasks/abc323_c
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(m), p(n,0);
    vector<P> q;
    vector<string> s(n);
    rep(i,m) {
        cin >> a[i];
        q.emplace_back(P(a[i],i));
    }
    ll best = 0;
    rep(i,n) {
        cin >> s[i];
        rep(j,m) if( s[i][j] == 'o' ) p[i] += a[j];
        p[i] += i;
        best = max(best,p[i]);
    }
    sort(q.begin(),q.end());
    reverse(q.begin(), q.end());
    rep(i,n) {
        ll ans = 0;
        rep(j,m) {
            if( p[i] >= best ) break;
            auto [v,idx] = q[j];
            if( s[i][idx] == 'o' ) continue;
            p[i] += v;
            ans++;
        }
        cout << ans << endl;
    }
    
    return 0;
}