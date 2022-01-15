/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc218/submissions/28520638
 * Submitted at: 2022-01-15 16:41:54
 * Problem URL: https://atcoder.jp/contests/abc218/tasks/abc218_a
 * Result: AC
 * Execution Time: 9 ms
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
    int n;string s; cin >> n >> s;
    if(s[n-1] == 'o')cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}  