/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/code-festival-2014-morning-easy/submissions/45783568
 * Submitted at: 2023-09-22 09:26:00
 * Problem URL: https://atcoder.jp/contests/code-festival-2014-morning-easy/tasks/code_festival_morning_easy_a
 * Result: AC
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
    cout << setprecision(10) << fixed;
    
    ll n; cin >> n;
    double ave = 0;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n-1) ave += a[i+1]-a[i];
    ave /= n-1;
    cout << ave << endl;
    
    return 0;
}