/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28464465
 * Submitted at: 2022-01-11 18:52:36
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_n
 * Result: AC
 * Execution Time: 76 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,comp = 0; cin >> n;
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    rep(i,n)comp += abs(a[i]-b[i]);
    cout << comp << endl;
    return 0;
}