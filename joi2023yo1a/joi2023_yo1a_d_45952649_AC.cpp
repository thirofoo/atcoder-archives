/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/joi2023yo1a/submissions/45952649
 * Submitted at: 2023-09-26 09:15:24
 * Problem URL: https://atcoder.jp/contests/joi2023yo1a/tasks/joi2023_yo1a_d
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
    
    ll n; cin >> n;
    vector<ll> a(2*n), cnt(2*n,0);
    rep(i,2*n-1) {
        cin >> a[i];
        cnt[a[i]-1]++;
    }
    rep(i,2*n) {
        if( cnt[i] == 1 ) {
            cout << i+1 << endl;
            return 0;
        }
    }
    
    return 0;
}