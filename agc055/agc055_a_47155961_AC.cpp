/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc055/submissions/47155961
 * Submitted at: 2023-11-02 19:21:58
 * Problem URL: https://atcoder.jp/contests/agc055/tasks/agc055_a
 * Result: AC
 * Execution Time: 37 ms
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
    
    ll n, turn = 1; string s; cin >> n >> s;
    vector<ll> p(3,0), ans(3*n,0);
    iota(p.begin(), p.end(), 0);
    do { 
        ll c1 = 0, c2 = 0, c3 = 0;
        rep(i,n) {
            if( ans[i] == 0 && s[i] == 'A'+p[0] ) c1++;
            if( ans[i+n] == 0 && s[i+n] == 'A'+p[1] ) c2++;
            if( ans[i+2*n] == 0 && s[i+2*n] == 'A'+p[2] ) c3++;
        }
        ll c_min = min({c1,c2,c3});
        c1 = 0, c2 = 0, c3 = 0;
        rep(i,n) {
            if( c1 < c_min && ans[i] == 0 && s[i] == 'A'+p[0] ) ans[i] = turn,c1++;
            if( c2 < c_min && ans[i+n] == 0 && s[i+n] == 'A'+p[1] ) ans[i+n] = turn,c2++;
            if( c3 < c_min && ans[i+2*n] == 0 && s[i+2*n] == 'A'+p[2] ) ans[i+2*n] = turn,c3++;
        }
        if( c_min ) turn++;
    } while(next_permutation(p.begin(), p.end()));
    rep(i,3*n) cout << ans[i];
    cout << endl;
    
    return 0;
}