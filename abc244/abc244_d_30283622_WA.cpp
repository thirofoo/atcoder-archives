/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/30283622
 * Submitted at: 2022-03-20 21:21:12
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_d
 * Result: WA
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
    char s1,s2,s3,t1,t2,t3; cin >> s1 >> s2 >> s3 >> t1 >> t2 >> t3;
    map<char,char> t;
    t[t1] = s1;
    t[t2] = s2;
    t[t3] = s3;
    if((t['R'] == 'R' && t['G'] == 'G' && t['B'] == 'B') || (t['R'] == 'G' && t['G'] == 'B' && t['B'] == 'R') || (t['R'] == 'B' && t['G'] == 'R' && t['B'] == 'G'))cout << "Yes" << endl;
    else cout << endl;
    return 0;
}