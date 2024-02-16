/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc006/submissions/50297240
 * Submitted at: 2024-02-16 10:09:35
 * Problem URL: https://atcoder.jp/contests/abc006/tasks/abc006_2
 * Result: AC
 * Execution Time: 14 ms
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
    
    ll n; cin >> n; n--;
    vector<ll> s = {0,0,1};
    if( n < 3  ) return cout << s[n] << endl, 0;
    rep(i,n-2) s.push_back( (s[i]+s[i+1]+s[i+2])%10007 );
    cout << s.back() << endl;
    
    return 0;
}