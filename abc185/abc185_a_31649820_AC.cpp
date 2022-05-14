/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc185/submissions/31649820
 * Submitted at: 2022-05-14 17:04:55
 * Problem URL: https://atcoder.jp/contests/abc185/tasks/abc185_a
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
    
    int a1,a2,a3,a4; cin >> a1 >> a2 >> a3 >> a4;
    cout << min(a1,min(a2,min(a3,a4))) << endl;
    return 0;
}