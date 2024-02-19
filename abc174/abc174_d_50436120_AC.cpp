/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc174/submissions/50436120
 * Submitted at: 2024-02-19 09:16:30
 * Problem URL: https://atcoder.jp/contests/abc174/tasks/abc174_d
 * Result: AC
 * Execution Time: 2 ms
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
    
    ll n; cin >> n; string s; cin >> s;
    ll ans = 0, num = 0;
    rep(i,s.size()) num += (s[i] == 'R');
    rep(i,num) ans -= (s[i] == 'R');
    ans += num;
    cout << ans << '\n';
    
    return 0;
}