/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc046/submissions/29606706
 * Submitted at: 2022-02-23 21:01:43
 * Problem URL: https://atcoder.jp/contests/abc046/tasks/abc046_a
 * Result: AC
 * Execution Time: 6 ms
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
    int a,b,c; cin >> a >> b >> c;
    set<int> d;
    d.insert(a);
    d.insert(b);
    d.insert(c);
    cout << d.size() << endl;
    return 0;
}