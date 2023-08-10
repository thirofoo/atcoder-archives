/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc313/submissions/44429405
 * Submitted at: 2023-08-10 15:02:21
 * Problem URL: https://atcoder.jp/contests/abc313/tasks/abc313_e
 * Result: AC
 * Execution Time: 22 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string s; cin >> n >> s;
    rep(i,n-1) if( s[i]-'0' != 1 && s[i+1]-'0' != 1 ) return cout << -1 << endl, 0;

    mint turn = 0;
    for(ll i=n-1;i>=1;i--) {
        if( s[i] == '1' ) turn++;
        else turn = turn+1 + (turn+1)*(s[i]-'0'-1);
        // cout << turn.val() << endl;
    }
    cout << endl << turn.val() << endl;
    
    return 0;
}