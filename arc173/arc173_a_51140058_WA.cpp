/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc173/submissions/51140058
 * Submitted at: 2024-03-11 00:07:50
 * Problem URL: https://atcoder.jp/contests/arc173/tasks/arc173_a
 * Result: WA
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    
    ll t; cin >> t;
    vector<ll> r(18, 1);
    reps(i,1,18) r[i] = r[i-1] * 9;

    while( t-- ) {
        ll k; cin >> k;
        ll left = 1, right = 1e18;
        while( right-left > 1 ) {
            ll mid = ( left+right ) / 2;
            string str = to_string(mid);
            ll cnt = (str[0]-'0') * r[str.size()-1], pre = str[0]-'0';
            reps(i,1,str.size()) {
                ll d = str[i]-'0';
                if( pre <= d ) d--;
                cnt += (d+1) * r[str.size()-i-1];
                pre = str[i]-'0';
            }
            if( cnt < k ) left = mid;
            else right = mid;
        }
        cout << right << endl;
    }
    
    return 0;
}