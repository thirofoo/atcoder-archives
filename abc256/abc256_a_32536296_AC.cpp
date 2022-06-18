/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/32536296
 * Submitted at: 2022-06-18 21:00:39
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_a
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll n; cin >> n;
    cout << (ll)pow(2,n) << endl;
    return 0;
}