/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc173/submissions/51141294
 * Submitted at: 2024-03-11 01:07:30
 * Problem URL: https://atcoder.jp/contests/arc173/tasks/arc173_a
 * Result: AC
 * Execution Time: 1 ms
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
    vector<ll> r(16, 1);
    reps(i,1,16) r[i] = r[i-1] * 9;

    while( t-- ) {
        ll k; cin >> k;
        ll left = 0, right = 1e15;
        while( right-left > 1 ) {
            ll mid = ( left+right ) / 2;
            string str = to_string(mid);

            ll cnt = (str[0]-'0'-1) * r[str.size()-1];
            // str.size() 未満の桁を考慮
            rep(i,str.size()-1) cnt += r[i+1];

            reps(i,1,str.size()) {
                ll d = str[i]-'0';
                if( str[i-1] < str[i] ) d--;
                cnt += d * r[str.size()-i-1];
                if( str[i-1] == str[i] ) break;
            }
            if( cnt < k ) left = mid;
            else right = mid;
        }
        cout << left << endl;
    }
    
    return 0;
}