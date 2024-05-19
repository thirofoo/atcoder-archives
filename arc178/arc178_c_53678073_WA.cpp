/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc178/submissions/53678073
 * Submitted at: 2024-05-19 22:46:15
 * Problem URL: https://atcoder.jp/contests/arc178/tasks/arc178_c
 * Result: WA
 * Execution Time: 220 ms
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
    
    ll n, l; cin >> n >> l;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) {
        if( a[i] <= l-2 || a[i] == 5 || a[i] == 11 ) {
            cout << -1 << endl;
            continue;
        }
        ll left = 0, right = 1e12;
        while( right-left > 1 ) {
            ll mid = (left+right)/2;
            ll sum = (l/2) * mid * ((l+1)/2);
            if( a[i] <= sum ) right = mid;
            else left = mid;
        }
        cout << right << endl;
    }
    
    return 0;
}