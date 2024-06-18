/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc314/submissions/54690016
 * Submitted at: 2024-06-18 18:10:55
 * Problem URL: https://atcoder.jp/contests/abc314/tasks/abc314_a
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
const ll INF = ((1LL << 62)-(1LL << 31));

string s = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    n += 2;
    rep(i, n) cout << s[i];
    cout << endl;
    
    return 0;
}