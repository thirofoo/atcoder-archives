/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc205/submissions/29839701
 * Submitted at: 2022-03-04 17:19:29
 * Problem URL: https://atcoder.jp/contests/abc205/tasks/abc205_c
 * Result: AC
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int a,b,c; cin >> a >> b >> c;
    if(a == b)return cout << "=" << '\n',0;
    c = (c%2 ? 1 : 2);
    if((ll)pow(a,c) > (ll)pow(b,c))cout << ">" << '\n';
    else if((ll)pow(a,c) < (ll)pow(b,c))cout << "<" << '\n';
    else cout << "=" << '\n';
    return 0;
}