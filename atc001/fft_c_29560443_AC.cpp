/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/atc001/submissions/29560443
 * Submitted at: 2022-02-21 13:55:34
 * Problem URL: https://atcoder.jp/contests/atc001/tasks/fft_c
 * Result: AC
 * Execution Time: 331 ms
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
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<int> con = convolution(a,b);
    cout << 0 << endl;
    rep(i,2*n-1) {
        cout << con[i] << endl;
    }
  return 0;
}