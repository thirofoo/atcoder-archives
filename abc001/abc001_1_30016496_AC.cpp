/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc001/submissions/30016496
 * Submitted at: 2022-03-12 12:54:27
 * Problem URL: https://atcoder.jp/contests/abc001/tasks/abc001_1
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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int h1,h2; cin >> h1 >> h2;
    cout << h1-h2 << endl;
    return 0;
}