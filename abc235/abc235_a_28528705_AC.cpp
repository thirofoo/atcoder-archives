/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/28528705
 * Submitted at: 2022-01-15 21:02:59
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_a
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
    int a = s[0]-'0';
    int b = s[1]-'0';
    int c = s[2]-'0';
    cout << (a+b+c)*111 << endl; 
    return 0;
}