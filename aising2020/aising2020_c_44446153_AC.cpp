/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/aising2020/submissions/44446153
 * Submitted at: 2023-08-11 09:28:57
 * Problem URL: https://atcoder.jp/contests/aising2020/tasks/aising2020_c
 * Result: AC
 * Execution Time: 34 ms
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
    vector<ll> ans(n+1, 0);
    for(ll i=1;i<=sqrt(n)+2;i++) {
        for(ll j=1;j<=sqrt(n)+2;j++) {
            for(ll k=1;k<=sqrt(n)+2;k++) {
                if( i*i + j*j + k*k + i*j + j*k + k*i <= n ) {
                    ans[i*i + j*j + k*k + i*j + j*k + k*i]++;
                }
            }
        }
    }
    rep(i,n) cout << ans[i+1] << endl;
    
    return 0;
}