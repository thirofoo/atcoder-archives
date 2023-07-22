/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc143/submissions/43821373
 * Submitted at: 2023-07-22 17:11:06
 * Problem URL: https://atcoder.jp/contests/abc143/tasks/abc143_d
 * Result: AC
 * Execution Time: 59 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    sort( l.begin(), l.end() );

    ll ans = n * (n-1) * (n-2) / 2 / 3;
    rep(i,n){
        for(ll j=i+1;j<n;j++){
            if( i == j ) continue;
            auto itr = lower_bound( l.begin(), l.end(), l[i]+l[j] );
            ans -= l.end() - itr;
        }
    }
    cout << ans << endl;
    
    return 0;
}