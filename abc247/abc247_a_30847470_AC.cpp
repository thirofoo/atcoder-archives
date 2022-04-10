/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/30847470
 * Submitted at: 2022-04-10 21:01:26
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_a
 * Result: AC
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
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    string s; cin >> s;
    s.pop_back();
    s.insert(0,"0");
    cout << s << endl;
    return 0;
}