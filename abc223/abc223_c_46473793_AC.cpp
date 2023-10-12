/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc223/submissions/46473793
 * Submitted at: 2023-10-12 18:43:40
 * Problem URL: https://atcoder.jp/contests/abc223/tasks/abc223_c
 * Result: AC
 * Execution Time: 21 ms
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
    vector<double> a(n),b(n);
    double total = 0;
    rep(i,n) {
        cin >> a[i] >> b[i];
        total += a[i]/b[i];
    }
    total /= 2;
    // cout << total << endl;
    double now = 0.0, time = 0.0;
    rep(i,n) {
        if( time+a[i]/b[i] <= total ) {
            time += a[i]/b[i];
            now += a[i];
        }
        else {
            cout << now + (total-time)*b[i] << endl;
            return 0;
        }
        // cout << now << " " << time << endl;
    }
    
    return 0;
}