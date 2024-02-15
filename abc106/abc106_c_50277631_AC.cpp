/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc106/submissions/50277631
 * Submitted at: 2024-02-15 10:16:31
 * Problem URL: https://atcoder.jp/contests/abc106/tasks/abc106_c
 * Result: AC
 * Execution Time: 1 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; ll k; cin >> s >> k;
    ll cnt = 0;
    rep(i,s.size()) {
        if( s[i] != '1' ) return cout << s[i] << endl, 0;
        cnt++;
        if( cnt == k ) return cout << 1 << endl, 0;
    }
    
    return 0;
}