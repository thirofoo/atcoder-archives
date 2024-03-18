/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc174/submissions/51407548
 * Submitted at: 2024-03-18 10:31:37
 * Problem URL: https://atcoder.jp/contests/arc174/tasks/arc174_c
 * Result: AC
 * Execution Time: 249 ms
 */

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using mint = atcoder::modint998244353;

int main() {
    int n; cin >> n;
    vector<mint> f1(n+1,0), f2(n+1,0);
    for(int i=n-1; i>=0; i--) {
        mint p = mint(i)/n, pn = mint(1) / (1-p*p);
        f1[i] = pn*((1-p)*f2[i+1] + p*(1-p)*f1[i+1] + p);
        f2[i] = pn*((1-p)*f1[i+1] + p*(1-p)*f2[i+1] + p*p);
    }
    cout << f1[0].val() << " " << f2[0].val() << '\n';
}