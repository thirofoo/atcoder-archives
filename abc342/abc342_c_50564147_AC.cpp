/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc342/submissions/50564147
 * Submitted at: 2024-02-24 21:05:06
 * Problem URL: https://atcoder.jp/contests/abc342/tasks/abc342_c
 * Result: AC
 * Execution Time: 68 ms
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
    
    ll n; cin >> n;
    string s; cin >> s;
    ll q; cin >> q;
    map<char, char> mp;
    rep(i,26) mp['a'+i] = 'a'+i;
    while(q--) {
        char c, d; cin >> c >> d;
        rep(i,26) if( mp['a'+i] == c ) mp['a'+i] = d;
    }
    rep(i,n) cout << mp[s[i]];
    cout << endl;
    
    return 0;
}