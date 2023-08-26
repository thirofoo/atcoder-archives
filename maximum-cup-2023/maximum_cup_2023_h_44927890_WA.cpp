/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2023/submissions/44927890
 * Submitted at: 2023-08-26 14:54:55
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2023/tasks/maximum_cup_2023_h
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
    
    ll n,x; cin >> n >> x;
    vector<ll> m(n);
    rep(i,n) cin >> m[i];
    rep(i,n) {
        bool f = true, before_f = false;
        ll min_num = 0, dig = 0;
        for(ll j=62;j>=0;j--) {
            before_f = (before_f || ( ((1ll << j) & x) > 0 ));
            if( f && before_f ) {
                if( min_num == 0 ) dig = j;
                f = ( ((1ll << j) & x) > 0 );
                min_num++;
            }
        }
        min_num = min(min_num-1, m[i]) - 1;
        // cerr << min_num << endl;
        ll next_x = (1ll << (dig+1));
        rep(j,min_num) next_x |= (1ll << j);
        x = next_x;
    }
    cout << x << endl;
    
    return 0;
}