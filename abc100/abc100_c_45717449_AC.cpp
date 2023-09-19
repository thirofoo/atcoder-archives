/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc100/submissions/45717449
 * Submitted at: 2023-09-19 09:19:14
 * Problem URL: https://atcoder.jp/contests/abc100/tasks/abc100_c
 * Result: AC
 * Execution Time: 2 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n);
    ll time = 0;
    rep(i,n) {
        cin >> a[i];
        while(a[i]%2 == 0) {
            time++;
            a[i] /= 2;
        }
    }
    cout << time << endl;
    
    
    return 0;
}