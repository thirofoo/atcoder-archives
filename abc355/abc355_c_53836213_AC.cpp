/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc355/submissions/53836213
 * Submitted at: 2024-05-25 21:06:39
 * Problem URL: https://atcoder.jp/contests/abc355/tasks/abc355_c
 * Result: AC
 * Execution Time: 12 ms
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
    
    ll n, t; cin >> n >> t;
    vector<ll> a(t), col(n,0), row(n,0);
    ll naname1 = 0, naname2 = 0;
    rep(i,t) {
        cin >> a[i];
        a[i]--;
    }
    rep(i,t) {
        ll r = a[i]/n, c = a[i]%n;
        row[r]++;
        col[c]++;
        if( r == c ) naname1++;
        if( r+c == n-1 ) naname2++;
        if( row[r] == n || col[c] == n || naname1 == n || naname2 == n ) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}