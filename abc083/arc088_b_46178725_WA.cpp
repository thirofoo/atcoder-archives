/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc083/submissions/46178725
 * Submitted at: 2023-10-03 14:25:23
 * Problem URL: https://atcoder.jp/contests/abc083/tasks/arc088_b
 * Result: WA
 * Execution Time: 2207 ms
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
    bitset<200005> bit, mask, cand;
    rep(i,n) bit.set(i,1-(s[i]-'0'));

    for(ll i=n-1;i>=0;i--) {
        mask.set();
        mask >>= 200005-i-1;
        cand.reset();

        ll time = (n-1)/(i+1) + 1;
        rep(j,time) {
            cand ^= ((bit & mask) >>= (i+1)*j);
            mask <<= i+1;
        }
        if( cand.count() == 0 || cand.count() == i+1 ) {
            return cout << i+1 << endl, 0;
        }
    }
    cout << 1 << endl;
    
    return 0;
}