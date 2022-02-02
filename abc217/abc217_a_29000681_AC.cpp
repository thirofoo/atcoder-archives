/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc217/submissions/29000681
 * Submitted at: 2022-02-02 11:42:44
 * Problem URL: https://atcoder.jp/contests/abc217/tasks/abc217_a
 * Result: AC
 * Execution Time: 8 ms
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
    string a,b; cin >> a >> b;
    if(a < b)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}