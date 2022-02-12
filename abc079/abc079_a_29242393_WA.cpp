/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc079/submissions/29242393
 * Submitted at: 2022-02-12 22:39:54
 * Problem URL: https://atcoder.jp/contests/abc079/tasks/abc079_a
 * Result: WA
 * Execution Time: 5 ms
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
    string n; cin >> n;
    if((n[0] == n[1] && n[1] == n[2]) || (n[1] == n[2] && n[2] == n[3]) || (n[0] == n[2] && n[2] == n[3]) || (n[0] == n[1] && n[1] == n[3]))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
