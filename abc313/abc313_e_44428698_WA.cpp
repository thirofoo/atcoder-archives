/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc313/submissions/44428698
 * Submitted at: 2023-08-10 14:33:41
 * Problem URL: https://atcoder.jp/contests/abc313/tasks/abc313_e
 * Result: WA
 * Execution Time: 10 ms
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
    rep(i,n-2) if( s[i+1]-'0' != 1 ) return cout << -1 << endl, 0;
    if( n == 2 && s[0]-'0' != 1 && s[1]-'0' != 1 ) return cout << -1 << endl, 0;

    // 最初と最後が 1~9 , 後は 1 の数列のみここに来る
    cout << n-2 + (s.back() - '0') << endl;
    
    return 0;
}