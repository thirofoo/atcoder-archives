/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/practice2/submissions/29562960
 * Submitted at: 2022-02-21 16:10:53
 * Problem URL: https://atcoder.jp/contests/practice2/tasks/practice2_f
 * Result: AC
 * Execution Time: 418 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m; cin >> n >> m;
    vector<int> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<int> con = convolution(a,b);
    rep(i,n+m-1)cout << con[i] << " ";
    cout << endl;
    return 0;
}