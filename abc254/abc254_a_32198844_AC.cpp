/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/32198844
 * Submitted at: 2022-06-04 21:00:52
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_a
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string n; cin >> n;
    cout << n[1] << n[2] << endl;
    return 0;
}