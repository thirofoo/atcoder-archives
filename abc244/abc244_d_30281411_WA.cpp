/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/30281411
 * Submitted at: 2022-03-20 21:17:22
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_d
 * Result: WA
 * Execution Time: 7 ms
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
    if((t[t1] == 'R' && t[t2] == 'G' && t[t3] == 'B') || (t[t1] == 'G' && t[t2] == 'B' && t[t3] == 'R') || (t[t1] == 'B' && t[t2] == 'G' && t[t3] == 'R'))cout << "Yes" << endl;
    else cout << endl;
    return 0;
}