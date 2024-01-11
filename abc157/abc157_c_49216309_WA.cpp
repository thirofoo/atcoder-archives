/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc157/submissions/49216309
 * Submitted at: 2024-01-11 19:06:08
 * Problem URL: https://atcoder.jp/contests/abc157/tasks/abc157_c
 * Result: WA
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
    
    ll n, m; cin >> n >> m;
    string str = "";
    rep(i,n) str += "?";
    rep(i,m) {
        ll s, c; cin >> s >> c; s--;
        if( s == 0 && c == 0 ) return cout << -1 << endl, 0;
        if( str[s] != '?' && str[s] != '0'+c ) return cout << -1 << endl, 0;
        str[s] = c + '0';
    }
    if( str[0] == '?' ) str[0] = '1';
    rep(i,n-1) str[i+1] = (str[i+1] == '?') ? '0' : str[i+1];
    cout << str << endl;
    
    return 0;
}