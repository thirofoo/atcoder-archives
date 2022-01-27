/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc224/submissions/28825677
 * Submitted at: 2022-01-27 20:11:08
 * Problem URL: https://atcoder.jp/contests/abc224/tasks/abc224_a
 * Result: WA
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
    if(s[s.size()-2] == 'e' && s[s.size()-1] == 'r')cout << "Yes" << endl;
    else if(s[s.size()-3] == 'i' && s[s.size()-2] == 's' && s[s.size()-1] == 't')cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}