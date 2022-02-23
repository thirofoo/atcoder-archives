/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc170/submissions/29606906
 * Submitted at: 2022-02-23 21:09:15
 * Problem URL: https://atcoder.jp/contests/abc170/tasks/abc170_a
 * Result: RE
 * Execution Time: 107 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
    vector<bool> f;
    f[a] = true;
    f[b] = true;
    f[c] = true;
    f[d] = true;
    f[e] = true;
    for(int i=1;i<=5;i++)if(!f[i])cout << i << endl;
    return 0;
}