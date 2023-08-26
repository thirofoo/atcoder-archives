/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2023/submissions/44926130
 * Submitted at: 2023-08-26 13:44:40
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2023/tasks/maximum_cup_2023_f
 * Result: WA
 * Execution Time: 5 ms
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
    
    ll n, m, k, s; cin >> n >> m >> k >> s;
    ll max_num = ((n+m)/k) * s;
    max_num += min( (n+m - ((n+m)/k)*k), s );
    ll min_num = ((n+m)/k) * s;
    min_num += max((n+m - ((n+m)/k)*k) - n, 0ll);
    if( n < min_num || max_num < n ) {
        cout << "No" << endl;
        return 0;
    }
    cerr << min_num << " " << max_num << endl;
    cout << "Yes" << endl;
    ll idx = max_num - n, time = n+m;
    string tmp = "", ans = "";
    rep(i,s) tmp += "0";
    rep(i,k-s) tmp += "1";
    while( time-- ) {
        ans += tmp[idx%k];
        idx++;
    }
    cout << ans << endl;
    
    return 0;
}