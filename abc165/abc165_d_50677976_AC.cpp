/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc165/submissions/50677976
 * Submitted at: 2024-02-27 16:56:38
 * Problem URL: https://atcoder.jp/contests/abc165/tasks/abc165_d
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
    
    ll a, b, n; cin >> a >> b >> n;
    // x = n or x = (n/b)*b -1 が候補そう
    auto f = [&](ll x) { return a*x/b - a*(x/b); };
    cout << max(f(n), f((n/b)*b-1)) << endl;
    
    return 0;
}