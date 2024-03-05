/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50920919
 * Submitted at: 2024-03-05 16:37:27
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_b
 * Result: AC
 * Execution Time: 89 ms
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
    
    ll n; cin >> n;
    rep(i,1ll << n) {
        string s = "";
        for(ll j=n-1; j>=0; j--) s += ( (1ll << j) & i ? ")" : "(" );
        ll cnt = 0;
        bool f = true;
        rep(i,n) {
            cnt += (s[i] == '(' ? 1 : -1);
            f &= (cnt >= 0);
        }
        if( f && cnt == 0 ) cout << s << endl;
    }
    
    return 0;
}