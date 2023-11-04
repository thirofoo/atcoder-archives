/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc327/submissions/47207221
 * Submitted at: 2023-11-04 21:00:55
 * Problem URL: https://atcoder.jp/contests/abc327/tasks/abc327_a
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
    
    ll n; string s; cin >> n >> s;
    rep(i,n-1) {
        if( (s[i] == 'a' && s[i+1] == 'b') || (s[i] == 'b' && s[i+1] == 'a') ) return cout << "Yes" << endl, 0;
    }
    cout << "No" << endl;
    
    return 0;
}