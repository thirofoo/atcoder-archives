/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc083/submissions/46179056
 * Submitted at: 2023-10-03 14:42:39
 * Problem URL: https://atcoder.jp/contests/abc083/tasks/arc088_b
 * Result: WA
 * Execution Time: 308 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    ll n = s.size();
    bitset<100005> b1, b2, cand;
    rep(i,n) b1.set(i,1-(s[i]-'0'));

    for(ll i=n-1;i>=0;i--) {
        cand = b1^b2;
        if( cand.count() == 0 || cand.count() == i+1 ) {
            return cout << i+1 << endl, 0;
        }
        if( b1.test(i) ) {
            b1.flip(i);
            b2 >>= 1;
            b2.flip(0);
            if( b2.test(i+1) ) {
                b2.flip(0);
                b2.flip(i+1);
            }
            if( b2.test(i+2) ) {
                b2.flip(1);
                b2.flip(i+2);
            }
        }
        else b2 >>= 1;
    }
    
    return 0;
}