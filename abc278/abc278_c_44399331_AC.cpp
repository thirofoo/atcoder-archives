/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc278/submissions/44399331
 * Submitted at: 2023-08-09 09:19:16
 * Problem URL: https://atcoder.jp/contests/abc278/tasks/abc278_c
 * Result: AC
 * Execution Time: 361 ms
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
    
    ll n,q; cin >> n >> q;
    map<ll,map<ll,ll>> mp;
    while(q--) {
        ll t,a,b; cin >> t >> a >> b;
        if(t == 1) {
            mp[a][b] = 1;
        }
        else if(t == 2) {
            mp[a][b] = 0;
        }
        else {
            cout << (mp[a][b] && mp[b][a] ? "Yes" : "No") << endl;
        }
    }
    
    return 0;
}