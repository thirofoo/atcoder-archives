/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc222/submissions/28244918
 * Submitted at: 2021-12-31 01:41:15
 * Problem URL: https://atcoder.jp/contests/abc222/tasks/abc222_a
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
    string n; cin >> n;
    if(n.size() != 4)rep(i,4-n.size())cout << 0;
    cout << n << endl;
    return 0;
}