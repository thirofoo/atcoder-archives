/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc224/submissions/28825821
 * Submitted at: 2022-01-27 20:21:27
 * Problem URL: https://atcoder.jp/contests/abc224/tasks/abc224_a
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
    string s; cin >> s;
    if(s[s.size()-2] == 'e' && s[s.size()-1] == 'r')cout << "er" << endl;
    else cout << "ist" << endl;
    return 0;
}