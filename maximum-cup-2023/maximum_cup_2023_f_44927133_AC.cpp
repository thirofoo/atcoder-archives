/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2023/submissions/44927133
 * Submitted at: 2023-08-26 14:26:59
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2023/tasks/maximum_cup_2023_f
 * Result: AC
 * Execution Time: 760 ms
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
    min_num += max( (n+m - ((n+m)/k)*k) - (k-s), 0ll);
    cerr << min_num << " " << max_num << endl;
    if( m < min_num || max_num < m ) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    string tmp = "";
    rep(i,s) tmp += "1";
    rep(i,k-s) tmp += "0";

    ll one_num = max_num, zero_num = n+m - one_num;
    rep(i,n+m) {
        cerr << one_num << " " << zero_num << endl;
        if( one_num == m ) {
            string ans = "";
            rep(j,n+m) ans += tmp[(i+j)%k];
            cout << ans << endl;
            return 0;
        }
        one_num += (tmp[i] == '1' ? -1 : 0);
        zero_num += (tmp[i] == '0' ? -1 : 0);
        one_num += (tmp[(i+n+m)%k] == '1' ? 1 : 0);
        zero_num += (tmp[(i+n+m)%k] == '0' ? 1 : 0);
    }
    
    return 0;
}